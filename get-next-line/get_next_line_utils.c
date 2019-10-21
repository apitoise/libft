/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:57:15 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/21 15:10:47 by apitoise         ###   ########.fr       */
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

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;
	int		cpy;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	res = (char *)malloc(size * sizeof(char) + 1);
	if (res == 0)
		return (0);
	cpy = 0;
	while (*s1)
	{
		res[cpy] = *s1;
		cpy++;
		s1++;
	}
	while (*s2)
	{
		res[cpy] = *s2;
		cpy++;
		s2++;
	}
	res[cpy] = '\0';
	return (res);
}

char		*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (*str == '\0' && (char)c != '\0')
			return (0);
		str++;
	}
	return ((char *)str);
}
