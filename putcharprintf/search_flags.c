/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:30:08 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/06 18:40:49 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		search_flags(const char *str, int pos, t_flags *flags)
{
	if (str[pos] == '-')
		flags->dash = 1;
	else if
		if (str[pos] == '0')
			flags->zero = 1;
	else if
		if (str[pos] == '.')
			flags->dot = 1;
	else if
		if (str[pos] == '*')
			flags->star = 1;
	else
		flags->flags = 0;
	return (pos + 1);
}

