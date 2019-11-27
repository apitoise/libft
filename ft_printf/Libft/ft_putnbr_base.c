/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:51:03 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/21 18:26:24 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_basehexa(unsigned long int n, char *base, t_flags *flags)
{
	char			c;

	if (n >= 16)
		ft_putnbr_basehexa(n / 16, base, flags);
	c = base[n % 16];
	ft_putchar(c, flags);
}
