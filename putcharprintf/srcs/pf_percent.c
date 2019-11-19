/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:38:09 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/19 18:28:46 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../Libft/libft.h"

void	flags_percent(int pos, t_flags *flags)
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
	ft_putchar('%', flags);
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

int		pf_percent(int pos, t_flags *flags)
{
	if (flags->flag > 0)
		flags_percent(pos, flags);
	else
		ft_putchar('%', flags);
	return (pos + 1);
}
