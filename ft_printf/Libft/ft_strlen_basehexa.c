/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_basehexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:50:28 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/21 17:08:59 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../headers/ft_printf.h"

int		ft_strlen_basehexa(unsigned long int n, char *base, t_flags *flags,
			int len)
{
	if (n >= 16)
		len = ft_strlen_basehexa(n / 16, base, flags, len);
	len++;
	return (len);
}
