/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:19:34 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/07 18:26:48 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		va;
	int			idx;

	va_start(va, str);
//	if (percent_nb((char *)str) < 0)
//		return (-1);
//	if (!(percent_nb((char *)str)))
//	{
//		ft_putstr((char *)str);
//		return (0);
//	}
//	else
	{
		idx = 0;
		while (str[idx])
		{
			if (str[idx] == '%')
				idx = ft_parsing(va, str, idx);
			while (str[idx] && str[idx] != '%')
			{
				write(1, &str[idx], 1);
				idx++;
			}
		}
	}
	return (0);
}
