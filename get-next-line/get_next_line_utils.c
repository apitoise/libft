/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:57:15 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/19 15:59:50 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		cpy;
	size_t	lalen;

	if (s == NULL || start < 0)
		return (NULL);
	lalen = ft_strlen((char *)s);
	if (start >= lalen)
		len = 0;
	else
		len = lalen - start < len ? lalen - start : len;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == 0)
		return (NULL);
	cpy = 0;
	while (len)
	{
		res[cpy] = s[start];
		cpy++;
		start++;
		len--;
	}
	res[cpy] = '\0';
	return (res);
}

char		*ft_strdup(const char *s1)
{
	int		len;
	char	*res;

	len = 0;
	while (s1[len])
		len++;
	res = malloc(len * sizeof(char) + 1);
	if (res == 0)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		res[len] = s1[len];
		len++;
	}
	res[len] = '\0';
	return (res);
}
