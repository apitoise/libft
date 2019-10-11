/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:41:33 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/10 13:04:32 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	remplir;

	if (count == 0 || size == 0)
		return (NULL);
	res = malloc(size * count);
	remplir = 0;
	while (remplir < count)
	{
		((char *)res)[remplir] == 0;
		remplir++;
	}
	return (res);
}
