/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:23:59 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/12 16:26:46 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *str, int base)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			res = (res * base) + (str[i] - 'a' + 10);
		else
			res = (res * base) + (str[i] - '0');
		i++;
	}
	return (res);
}
