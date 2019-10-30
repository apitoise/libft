/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:42:26 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/30 16:36:02 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int		len;
	int		error;
	int		pos;
	char	*res;

	len = 0;
	while (str[len] && str[len] != '%')
		len++;
	pos = 0;
	if (!(res = (char *)malloc(len * sizeof(char) + 1)))
		return (-1);
	while (pos++ < len)
		res[pos] = str[pos];
	if (str[len] == '%')
	{
		if ((error = ft_parsing((char *)str, len, res) < 0))
		{
			free(res);
			return (-1);
		}
	}
	ft_putstr(res);
	return (0);
}
