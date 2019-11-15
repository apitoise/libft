/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:39:38 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/15 17:28:42 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_c(char c, int pos, t_flags *flags)
{
	if (flags->dash > 0)
	{
		flags->zero = 0;
		ft_putchar(c);
		while (flags->width > 1)
		{
			ft_putchar(' ');
			flags->width--;
		}
	}
	if (flags->zero > 0)
	{
		while (flags->width > 1)
		{
			ft_putchar('0');
			flags->width--;
		}
		ft_putchar(c);
	}
	if (flags->dot > 0)
		ft_putchar(c);
}

int		pf_c(int c, int pos, t_flags *flags)
{
//	while (flags->digit > 1)
//	{
//		ft_putchar(' ');
//		flags->digit--;
//	}
	if (flags->flag > 0)
		flags_c(c, pos, flags);
	else
		write(1, &c, 1);
	return (pos + 1);
}
