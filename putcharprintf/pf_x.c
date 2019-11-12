/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:26:49 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/07 19:01:23 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_x(va_list va, int pos, t_flags flags)
{
	unsigned long int	n;
	char				base[17];

	ft_strlcpy(base, "0123456789abcdef", 17);
	n = (unsigned long int)(va_arg(va, void *));
	ft_putnbr_basehexa(n, base);
	return (pos + 1);
}
