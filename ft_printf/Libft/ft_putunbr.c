/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:26:58 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/20 16:45:10 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putunbr(unsigned int n, t_flags *flags)
{
	unsigned int	nbr;

	if (n < 0)
		nbr = 4294967295 + n + 1;
	else
		nbr = n;
	if (n / 10)
		ft_putnbr(nbr / 10, flags);
	ft_putchar(((nbr % 10) + 48), flags);
}
