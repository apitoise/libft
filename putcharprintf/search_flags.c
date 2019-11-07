/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:30:08 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/07 18:26:45 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(const char *str, int pos)
{
	if (str[pos] == '-' || str[pos] == '0' || str[pos] == '.' || str[pos] == '*')
		return (0);
	else
		return (1);
}

int		search_flags(const char *str, int pos, t_flags *flags)
{
	if (!(is_flag(str, pos)))
	{
		flags->flag = 1;
		if (str[pos] == '-')
			flags->dash = 1;
		if (str[pos] == '0')
			flags->zero = 1;
		if (str[pos] == '.')
			flags->dot = 1;
		if (str[pos] == '*')
			flags->star = 1;
	}
	else
		flags->flag = 0;
	return (pos + 1);
}

