/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:39:38 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/18 15:47:19 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void	flags_c(char c, int pos, t_flags *flags)
{
	if (flags->dash > 0 || flags->dot > 0)
		flags->zero = 0;
	if (flags->zero > 0)
	{
		if (flags->star == 0)
		{
			while (flags->width > 1)
			{
				ft_putchar('0', flags);
				flags->width--;
			}
		}
		else
			flags->dash = 1;
	}
	ft_putchar(c, flags);
	if (flags->dash > 0)
	{
		flags->zero = 0;
 		while (flags->width > 1)
		{
			ft_putchar(' ', flags);
			flags->width--;
		}
	}
}

int		pf_c(int c, int pos, t_flags *flags)
{
	if (flags->flag > 0)
		flags_c(c, pos, flags);
	else
		ft_putchar(c, flags);
	return (pos + 1);
}
