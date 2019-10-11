/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:47:25 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/10 17:12:41 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (len == 0)
		return (dst);
	if (source > dest)
	{
		while (*dest)
			dest++;
		while (*source)
			source++;
		while (len--)
			*dest-- = *source--;
		return (dst);
	}
	while (len)
	{
		*dest = *source;
		dest++;
		source++;
		len--;
	}
	return (dst);
}
