/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:51:46 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/09 18:17:51 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)s;
	while (*s2 != (char)c && n > 0)
	{
		n--;
		s2++;
	}
	if (*s2 == (char)c)
		return (s2);
	else
		return (NULL);
}
