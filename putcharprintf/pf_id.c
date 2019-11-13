/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_id.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:00:33 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/13 18:02:13 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_id(va_list va, int pos, t_flags *flags)
{
	if (flags->dash > 0)
	{
		flags->zero = 0;
		ft_putnbr(va_arg(va, unsigned int));
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
		ft_putnbr(va_arg(va, unsigned int));
	}
	if (flags->dot > 0)
		ft_putnbr(va_arg(va, unsigned int));
	if (flags->star > 0)
	{
		flags->width = va_arg(va, int);
		while (flags->width > 1)
		{
			ft_putchar(' ');
			flags->width--;
		}
		ft_putnbr(va_arg(va, unsigned int));
	}
}

int		pf_id(va_list va, int pos, t_flags flags)
{
	if (flags.flag > 0)
		flags_id(va, pos, &flags);
	else
		ft_putnbr(va_arg(va, unsigned int));
	return (pos + 1);
}
