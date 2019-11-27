/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:10:02 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/27 15:02:07 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../Libft/libft.h"

int		itoa_func_u(unsigned int nbr)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa(nbr);
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}

void	ft_dot_u(unsigned int nbr, t_flags *flags)
{
	int		lenbis;
	int		tmp;

	tmp = flags->precision;
	lenbis = itoa_func_u(nbr);
	if (flags->dot > 0 && flags->precision == 0 && nbr == 0)
		lenbis = 0;
	if (nbr < 0)
		flags->len += 1;
	if (flags->dash == 0)
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
	if (nbr >= 0)
		while (flags->precision-- > lenbis)
			ft_putchar('0', flags);
	flags->precision = tmp;
}

void	flags_u(unsigned int nbr, t_flags *flags)
{
	if (flags->dash > 0 || flags->dot > 0)
		flags->zero = 0;
	if (flags->zero > 0)
		while (flags->width-- > flags->len)
			ft_putchar('0', flags);
	if (flags->dot > 0)
		ft_dot_u(nbr, flags);
	if (!(flags->dot > 0 && flags->precision <= 0 && nbr == 0))
		ft_putunbr(nbr, flags);
	if (flags->dash > 0)
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
}

int		pf_u(int nbr, int pos, t_flags *flags)
{
	unsigned int		n;

	if (nbr < 0)
		n = 4294967295 + nbr + 1;
	else
		n = nbr;
	flags->len = itoa_func_u(n);
	flags->len = (flags->len > flags->precision) ? flags->len
		: flags->precision;
	if (flags->dot > 0 && flags->precision == 0 && nbr == 0)
		flags->len = 0;
	if (flags->flag > 0)
		flags_u(n, flags);
	else
	{
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
		if (flags->dot > 0 && flags->precision == 0 && nbr == 0)
			return (pos + 1);
		else
			ft_putunbr(n, flags);
	}
	return (pos + 1);
}
