/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:23:50 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/31 14:23:56 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned int nb, char *base)
{
	char	*res;
	int		size;
	int		len;
	int		tmp;
	int		i;

	size = 1;
	len = ft_strlen(base);
	tmp = len;
	while (tmp >= len)
	{
		tmp /= len;
		size++;
	}
	res = (char *)malloc(size + 1);
	res[size] = '\0';
	i = size - 1;
	while (i >= 0)
	{
		res[i] = base[nb % len];
		nb /= len;
		i--;
	}
	return (res);
}