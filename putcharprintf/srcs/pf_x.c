/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:26:49 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/19 18:29:24 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../Libft/libft.h"

int		itoa_func_x(unsigned int nbr)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa(nbr);
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}

void	ft_dot_x(int nbr, int pos, t_flags *flags, char *base)
{
	int		lenbis;

	lenbis = 0;
	lenbis = ft_strlen_basehexa(nbr, base, flags, lenbis);
	if (nbr < 0)
		flags->len += 1;
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

void	flags_x(unsigned long int nbr, int pos, t_flags *flags, char *base)
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
		ft_dot_x(nbr, pos, flags, base);
	ft_putnbr_basehexa(nbr, base, flags);
	if (flags->dash > 0)
	{
		while (flags->width > flags->len)
		{
			ft_putchar(' ', flags);
			flags->width--;
		}
	}
}

int			pf_x(unsigned long int n, int pos, t_flags *flags)
{
	char				base[17];
	int					len;

	len = 0;
	ft_strlcpy(base, "0123456789abcdef", 17);
	flags->len = ft_strlen_basehexa(n, base, flags, len);
	flags->len = (flags->len > flags->precision) ? flags->len
		: flags->precision;
	if (flags->flag > 0)
		flags_x(n, pos, flags, base);
	else
	{
		while (flags->width > flags->len)
		{
			ft_putchar(' ', flags);
			flags->width--;
		}
		ft_putnbr_basehexa(n, base, flags);
	}
	return (pos + 1);
}
