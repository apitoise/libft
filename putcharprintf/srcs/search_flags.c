/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:30:08 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/19 18:31:41 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../Libft/libft.h"

int		ft_star(va_list va, const char *str, int pos, t_flags *flags)
{
	int		nbr;

	nbr = va_arg(va, int);
	if (nbr < 0)
		nbr = -nbr;
	if (str[pos - 1] == '0' || str[pos - 1] == '-' || str[pos - 1] == '.')
	{
		if (str[pos - 1] == '0' || str[pos - 1] == '-')
			flags->width = nbr;
		if (str[pos - 1] == '.')
			flags->precision = nbr;
	}
	else
		flags->width = nbr;
	return (pos + 1);
}

int		ft_width(va_list va, const char *str, int pos, t_flags *flags)
{
	pos += 1;
	if (ft_isdigit(str[pos]))
	{
		flags->width = ft_atoi(&str[pos]);
		while (ft_isdigit(str[pos]))
			pos++;
	}
	return (pos);
}

int		ft_precision(va_list va, const char *str, int pos, t_flags *flags)
{
	pos += 1;
	if (ft_isdigit(str[pos]))
	{
		flags->precision = ft_atoi(&str[pos]);
		while (ft_isdigit(str[pos]))
			pos++;
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
	if (ft_isdigit(str[pos]) && str[pos] != '0')
		pos = ft_digitflags(str, pos, flags);
	if (!(is_flag(str, pos)))
	{
		if (str[pos] == '0' || str[pos] == '-' || str[pos] == '.')
			flags->flag = 1;
		if (str[pos] == '0')
			flags->zero = 1;
		if (str[pos] == '-')
			flags->dash = 1;
		if (str[pos] == '0' || str[pos] == '-')
			pos = ft_width(va, str, pos, flags);
		if (str[pos] == '.')
		{
			flags->dot = 1;
			pos = ft_precision(va, str, pos, flags);
		}
		if (str[pos] == '*')
		{
			flags->star = 1;
			pos = ft_star(va, str, pos, flags);
		}
	}
	return (pos);
}
