/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:39:38 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/13 16:47:07 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_c(va_list va, int pos, t_flags *flags)
{
	if (flags->dash > 0)
	{
		flags->zero = 0;
		ft_putchar(va_arg(va, int));
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
		ft_putchar(va_arg(va, int));
	}
	if (flags->dot > 0)
		ft_putchar(va_arg(va, int));
}	

int		pf_c(va_list va, int pos, t_flags flags)
{
	char	c;

	if (flags.flag > 0)
		flags_c(va, pos, &flags);
	else
	{
	c = va_arg(va, int);
	write(1, &c, 1);
	}
	return (pos + 1);
}
