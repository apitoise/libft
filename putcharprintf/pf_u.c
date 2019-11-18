/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:10:02 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/18 16:36:03 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int		itoa_func_u(int nbr)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa(nbr);
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}

void	ft_dot_u(int nbr, int pos, t_flags *flags)
{
	int		lenbis;

	lenbis = itoa_func_u(nbr);
	if (nbr < 0)
	{
		lenbis -= 1;
		flags->len += 1;
	}
	while (flags->width > flags->len && flags->dash == 0)
	{
		ft_putchar(' ', flags);
		flags->width--;
	}
	while (flags->precision > lenbis)
	{
		ft_putchar('0', flags);
		flags->precision--;
	}
}

void	flags_u(int nbr, int pos, t_flags *flags)
{
	if (flags->dash > 0 || flags->dot > 0)
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
		ft_dot_u(nbr, pos, flags);
	ft_putunbr(nbr, flags);
	if (flags->dash > 0)
	{
		while (flags->width > flags->len)
		{
			ft_putchar(' ', flags);
			flags->width--;
		}
	}
}

int		pf_u(int nbr, int pos, t_flags *flags)
{
	flags->len = itoa_func_u(nbr);
	flags->len = (flags->len > flags->precision) ? flags->len
		: flags->precision;
	if (flags->flag > 0)
		flags_u(nbr, pos, flags);
	else
	{
		while (flags->width > flags->len)
		{
			ft_putchar(' ', flags);
			flags->width--;
		}
		ft_putunbr(nbr, flags);
	}
	return (pos + 1);
}
