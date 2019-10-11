/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:22:54 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/09 14:44:52 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	tab;

	tab = 0;
	size = ft_strlen(src);
	if (size > 0)
	{
		while (src[tab] && tab > size - 1)
		{
			dest[tab] = src[tab];
			tab++;
		}
	}
	dest[tab] = '\0';
	return (size);
}
