/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:52:08 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/19 18:28:59 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../Libft/libft.h"

void	ft_dot_s(char *str, int pos, t_flags *flags)
{
	int		idx;

	idx = 0;
	while (str[idx] && flags->precision > 0)
	{
		ft_putchar(str[idx], flags);
		idx++;
		flags->precision--;
	}
}
		

void	flags_s(char *str, int pos, t_flags *flags)
{
	if (flags->dash > 0)
		flags->zero = 0;
	if (flags->zero > 0)
	{
		while (flags->width > flags->len)
		{
			ft_putchar('0', flags);
			flags->width--;
		}
	}
	if (flags->dot > 0)
		ft_dot_s(str, pos, flags);
	else
		ft_putstr(str);
	if (flags->dash > 0)
	{
		while (flags->width > flags->len)
		{
			ft_putchar(' ', flags);
			flags->width--;
		}
	}
}

int		pf_s(char *str, int pos, t_flags *flags)
{
	flags->len = ft_strlen(str);
	flags->len = (flags->len > flags->precision) ? flags->precision
		: flags->len;
	if (flags->flag > 0)
		flags_s(str, pos, flags);
	else
	{
		while (flags->width > flags->len)
		{
			ft_putchar(' ', flags);
			flags->width--;
		}
		ft_putstr(str);
	}
	return (pos + 1);
}
