/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:56:50 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/11 15:09:54 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isset(char c, char const *set))
{
	int		i;

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
	int		idx;
	int		nb;

	idx = 0;
	nb = 0;
	while (ft_isset(s1[idx], set) == 1 && s1[idx])
	{
		nb++;
		idx++;
	}
	return (nb);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		idx;
	int		min;
	int		max;

	idx = 0;
	min = 0;
	res = (char *)malloc((ft_strlen(s1) - ft_nbset(s1, set) * sizeof(char) + 1))
	while (s1[min])
	{
		if (ft_isset(s1[min], set) == 1)
			min++;
		

int		main(int argc, char **argv)
{
	printf("%s", ft_strtrim(argv[1], argv[2]));
	return (0);
}
