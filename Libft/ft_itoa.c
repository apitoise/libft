/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:26:27 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/14 12:26:30 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_len(int n)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		res++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		idx;

	res = (char *)malloc((ft_len(n) + 1) * sizeof(char));
	if (res == 0)
		return (0);
	idx = 0;
	if (n < 0)
	{
		res[idx++] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		res[idx] = (n % 10) + 48;
		n = n / 10;
		idx++;
	}
	if (n == 0)
	{
		res[idx] = '0';
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
