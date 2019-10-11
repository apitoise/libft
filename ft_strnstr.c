/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:22:08 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/09 16:37:01 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *hayshack, const char *needle, size_t len)
{
	size_t		savelen;
	int			meule;
	int			aiguille;

	if (ft_strlen(needle) == 0)
		return ((char *)hayshack);
	meule = 0;
	while (hayshack[meule])
	{
		aiguille = 0;
		while (hayshack[meule] != needle[aiguille] && len--)
			meule++;
		while (hayshack[meule] == needle[aiguille]
				&& hayshack[meule] && needle[aiguille] && len--)
		{
			if (needle[aiguille] == '\0')
				return ((char *)&hayshack[meule - aiguille]);
			meule++;
			aiguille++;
		}
	}
	return ((char *)hayshack);
}
