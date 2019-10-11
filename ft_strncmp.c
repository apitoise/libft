/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:17:51 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/09 13:09:44 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t i)
{
	size_t comp;

	comp = 0;
	if (i == 0)
		return (0);
	while (comp < i - 1 && (s1[comp] == s2[comp]) && s1[comp] && s2[comp])
		comp++;
	return (s1[comp] - s2[comp]);
}
