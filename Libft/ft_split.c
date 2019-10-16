/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:27:13 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/15 17:28:12 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countword(char const *s, char c)
{
	int	res;
	int	new;

	res = 0;
	new = 1;
	while (*s)
	{
		if (*s != c && new == 1)
		{
			res++;
			new = 0;
		}
		if (*s == c && new == 0)
			new = 1;
		s++;
	}
	return (res);
}

int		ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

void		ft_createword(char **str, const char *src, char c)
{
	char	*word;

	*str = malloc((ft_wordlen(src, c) + 1) * sizeof(char));
	word = *str;
	while (*src && *src != c)
	{
		*word = *src;
		word++;
		src++;
	}
	*word = '\0';
}

char		**ft_split(char const *s, char c)
{
	char	**res;
	char	**res2;
	int	new;

	if (!s || !(res = malloc((ft_countword(s, c) + 1) * sizeof(char *))))
		return (NULL);
	res2 = res;
	new = 0;
	while (*s)
	{
		if (*s != c && new == 0)
		{
			new = 1;
			ft_createword(res, s, c);
			res++;
		}
		if (*s == c && new == 1)
			new = 0;
		s++;
	}
	*res = NULL;
	return (res2);
}
