/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_id.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:00:33 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/19 18:28:18 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../Libft/libft.h"

int		itoa_func(int nbr)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa(nbr);
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}

void	ft_dot(int nbr, int pos, t_flags *flags)
{
	int		lenbis;

	lenbis = itoa_func(nbr);
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
	if (nbr < 0)
		ft_putchar('-', flags);
	while (flags->precision > lenbis)
	{
		ft_putchar('0', flags);
		flags->precision--;
	}
}

void	flags_id(int nbr, int pos, t_flags *flags)
{
	if (flags->dash > 0 || flags->dot > 0)
		flags->zero = 0;
	if (nbr < 0 && flags->dot == 0)
		ft_putchar('-', flags);
	if (flags->zero > 0)
	{
		while (flags->width > flags->len)
		{
			ft_putchar('0', flags);
			flags->width--;
		}
	}
	if (flags->dot > 0)
		ft_dot(nbr, pos, flags);
	ft_putnbr(nbr, flags);
	if (flags->dash > 0)
	{
		while (flags->width > flags->len)
		{
			ft_putchar(' ', flags);
			flags->width--;
		}
	}
}

int		pf_id(int nbr, int pos, t_flags *flags)
{
	flags->len = itoa_func(nbr);
	flags->len = (flags->len > flags->precision) ? flags->len
		: flags->precision;
	if (flags->flag > 0)
		flags_id(nbr, pos, flags);
	else
	{
		while (flags->width > flags->len)
		{
			ft_putchar(' ', flags);
			flags->width--;
		}
		if (nbr < 0)
			ft_putchar('-', flags);
		ft_putnbr(nbr, flags);
	}
	return (pos + 1);
}
