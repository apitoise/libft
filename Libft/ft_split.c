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

int			ft_countwords(char const *s, char c)
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
		if (*s == c)
			new = 1;
		s++;
	}
	return (res);
}

char		**ft_split(char const *s, char c)
{
	char	**res;
	int		idx;
	int		nb;
	int		len;
	int		cpy;

	res = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (res == 0)
		return (0);
	idx = 0;
	nb = 0;
	while (s[idx])
	{
		len = 0;
		while (s[idx] == c)
			idx++;
		while (s[idx + len] != c)
			len++;
		res[nb] = (char *)malloc((len + 1) * sizeof(char));
		cpy = 0;
		while (s[idx] != c && s[idx])
			res[nb][cpy++] = s[idx++];
		res[nb][cpy] = '\0';
		nb++;
	}
	res[nb] = 0;
	return (res);
}
