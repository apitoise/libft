/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:30:08 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/13 18:02:20 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width(va_list va, const char *str, int pos, t_flags *flags)
{
	pos += 1;
	flags->width = 0;
	if (ft_isdigit(str[pos]))
	{
		flags->width = ft_atoi(&str[pos]);
		while (ft_isdigit(str[pos]))
			pos++;
		return (pos);
	}
	if (str[pos] == '*')
	{
		flags->width = va_arg(va, int);
		flags->flag = 0;
		return (pos + 1);
	}
	return (pos);
}

int		ft_precision(va_list va, const char *str, int pos, t_flags *flags)
{
	pos += 1;
	flags->precision = 0;
	if (ft_isdigit(str[pos]))
	{
		flags->precision = ft_atoi(&str[pos]);
		while (ft_isdigit(str[pos]))
			pos++;
		return (pos);
	}
	if (str[pos] == '*')
	{
		flags->precision = va_arg(va, int);
		flags->flag = 0;
		return (pos + 1);
	}
	return (pos);
}

int		is_flag(const char *str, int pos)
{
	if (str[pos] == '-' || str[pos] == '0' || str[pos] == '.' 
			|| str[pos] == '*')
		return (0);
	else
		return (1);
}

int		search_flags(va_list va, const char *str, int pos, t_flags *flags)
{
	if (!(is_flag(str, pos)))
	{
		flags->flag = 1;
		if (str[pos] == '0')
		{
			flags->zero = 1;
			pos = ft_width(va, str, pos, flags);
		}
		if (str[pos] == '-')
		{
			flags->dash = 1;
			pos = ft_width(va, str, pos, flags);
		}
		if (str[pos] == '.')
		{
			flags->dot = 1;
			pos = ft_precision(va, str, pos, flags);
		}
		if (str[pos] == '*')
			flags->star = 1;
	}
	else
		flags->flag = 0;
	return (pos);
}
