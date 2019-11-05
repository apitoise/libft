/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:32:44 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/04 13:34:00 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	s1_len = s1 ? ft_strlen((char *)s1) : 0;
	s2_len = s2 ? ft_strlen((char *)s2) : 0;
	if (!(result = malloc(sizeof(char) *
	(s1_len + s2_len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}
