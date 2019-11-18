/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:26:49 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/18 14:39:37 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int			pf_cx(va_list va, int pos, t_flags *flags)
{
	unsigned long int	n;
	char				base[17];

	ft_strlcpy(base, "0123456789ABCDEF", 17);
	n = (unsigned long int)(va_arg(va, void *));
	ft_putnbr_basehexa(n, base, flags);
	return (pos + 1);
}
