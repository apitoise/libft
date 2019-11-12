/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:30:08 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/12 18:56:39 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width(const char *str, int pos, t_flags *flags)
{
	pos += 1;
	flags->width = 0;
	if (ft_isdigit(str[pos]))
	{
		flags->width = ft_atoi(&str[pos]);
		pos++;
	}
	return (pos);
}
		
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
		{
			flags->dash = 1;
			pos = ft_width(str, pos, flags);
		}
		if (str[pos] == '0')
		{
			flags->zero = 1;
			pos = ft_width(str, pos, flags);
		}
		if (str[pos] == '.')
			flags->dot = 1;
		if (str[pos] == '*')
			flags->star = 1;
	}
	else
		flags->flag = 0;
	return (pos + 1);
}

