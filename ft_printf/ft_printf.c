/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:42:26 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/03 17:43:35 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_resultat	resultat;
	t_data		data;
	va_list		va;

	va_start(va, str);
	data.str = (char *)str;
	if (percent_nb(data.str) < 0)
		return (-1);
	if (!(percent_nb(data.str)))
	{
		ft_putstr(data.str);
		return (0);
	}
	else
	{
		data.pos = 0;
		while (data.str[data.pos])
		{
			while (data.str[data.pos] && data.str[data.pos] != '%')
				data.pos++;
			if (data.pos > 0)
				ft_strlcpy(resultat.res, data.str, data.pos + 1);
			if (data.str[data.pos] == '%')
			{
				data.conv = data.str[data.pos + 1];
				resultat.res = ft_parsing(va, data, resultat);
			}
			data.pos++;
		}
	}
	ft_putstr(resultat.res);
	return (0);
}
