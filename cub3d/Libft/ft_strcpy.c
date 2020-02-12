/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:45:48 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/31 18:49:38 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, char *src)
{
	int		cpy;
	int		len;

	len = ft_strlen(src);
	cpy = 0;
	while (cpy < len)
	{
		dst[cpy] = src[cpy];
		cpy++;
	}
	dst[cpy] = '\0';
	return (dst);
}
