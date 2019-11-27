/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:39:38 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/21 18:33:00 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../Libft/libft.h"

void	flags_c(char c, t_flags *flags)
{
	if (flags->dash > 0)
		flags->zero = 0;
	if (flags->zero > 0)
	{
		if (flags->star == 0)
			while (flags->width-- > 1)
				ft_putchar('0', flags);
		else
			flags->dash = 1;
	}
	else if (flags->zero == 0 && flags->dash == 0)
		while (flags->width-- > 1)
			ft_putchar(' ', flags);
	ft_putchar(c, flags);
	if (flags->dash > 0)
	{
		flags->zero = 0;
		while (flags->width-- > 1)
			ft_putchar(' ', flags);
	}
}

int		pf_c(int c, int pos, t_flags *flags)
{
	if (flags->flag > 0)
		flags_c(c, flags);
	else
	{
		while (flags->width-- > 1)
			ft_putchar(' ', flags);
		ft_putchar(c, flags);
	}
	return (pos + 1);
}
