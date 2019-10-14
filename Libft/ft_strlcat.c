/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:03:08 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/10 12:14:21 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	tab;
	size_t	lendest;
	size_t	res;

	lendest = 0;
	while (dest[lendest])
		lendest++;
	res = 0;
	while (src[res])
		res++;
	res = res + lendest;
	tab = 0;
	while (src[tab] && (tab < size - lendest - 1))
	{
		dest[lendest] = src[tab];
		lendest++;
		tab++;
	}
	dest[lendest] = '\0';
	return (res);
}
