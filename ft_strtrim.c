/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:56:50 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/14 12:00:35 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_conststrlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int			ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int			ft_nbset(char const *s1, char const *set)
{
	int	idx;
	int	nb;
	int	end;

	idx = 0;
	nb = 0;
	while (ft_isset(s1[idx], set) == 1 && s1[idx])
	{
		nb++;
		idx++;
	}
	end = ft_conststrlen(s1);
	while (ft_isset(s1[end], set) == 1 && end > 0)
	{
		nb++;
		end--;
	}
	return (nb);
}

int			ft_nbsetmax(char const *s1, char const *set)
{
	int	len;

	len = ft_conststrlen(s1) - 1;
	while (ft_isset(s1[len], set) == 1 && len > 0)
		len--;
	return (len);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		idx;
	int		min;
	int		max;

	min = 0;
	while (ft_isset(s1[min], set) == 1)
		min++;
	max = ft_nbsetmax(s1, set);
	res = (char *)malloc((max - min) * sizeof(char) + 1);
	if (res == 0)
		return (0);
	idx = 0;
	while (min <= max)
	{
		res[idx] = s1[min];
		min++;
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
