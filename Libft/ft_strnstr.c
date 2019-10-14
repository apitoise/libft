/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:22:08 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/14 15:25:39 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int			meule;
	int			aiguille;

	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	meule = 0;
	while (haystack[meule])
	{
		aiguille = 0;
		while (haystack[meule] != needle[aiguille] && len--)
			meule++;
		while (haystack[meule] == needle[aiguille]
				&& haystack[meule] && needle[aiguille] && len--)
		{
			if (needle[aiguille] == '\0')
				return ((char *)&haystack[meule - aiguille]);
			meule++;
			aiguille++;
		}
	}
	return ((char *)haystack);
}
