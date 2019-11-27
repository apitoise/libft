/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:26:49 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/22 18:56:15 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../Libft/libft.h"

void			ft_dot_x(unsigned long int nbr, t_flags *flags, char *base
				, int len)
{
	int		lenbis;
	int		tmp;

	tmp = flags->precision;
	lenbis = len;
	lenbis = ft_strlen_basehexa(nbr, base, flags, lenbis);
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

void			flags_x(unsigned long int nbr, t_flags *flags, char *base
				, int len)
{
	if (flags->dash > 0 || flags->dot > 0)
		flags->zero = 0;
	if (flags->zero > 0)
		while (flags->width-- > flags->len)
			ft_putchar('0', flags);
	if (flags->dot > 0)
		ft_dot_x(nbr, flags, base, len);
	if (!(flags->dot > 0 && flags->precision <= 0 && nbr == 0))
		ft_putnbr_basehexa(nbr, base, flags);
	if (flags->dash > 0)
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
}

unsigned int	unsigned_func_c(int n)
{
	unsigned int	nb;

	if (n < 0)
		nb = 4294967295 + n + 1;
	else
		nb = n;
	return (nb);
}

int				pf_x(int n, int pos, t_flags *flags)
{
	char				base[17];
	int					len;
	unsigned int		nb;

	len = 0;
	nb = unsigned_func_c(n);
	ft_strlcpy(base, "0123456789abcdef", 17);
	flags->len = ft_strlen_basehexa(nb, base, flags, len);
	flags->len = (flags->len > flags->precision) ? flags->len
		: flags->precision;
	if (flags->dot > 0 && flags->precision == 0 && n == 0)
		flags->len = 0;
	if (flags->flag > 0)
		flags_x(nb, flags, base, len);
	else
	{
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
		if (flags->dot > 0 && flags->precision == 0 && n == 0)
			return (pos + 1);
		else
			ft_putnbr_basehexa(nb, base, flags);
	}
	return (pos + 1);
}
