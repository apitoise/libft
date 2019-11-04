/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:42:26 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/04 17:00:53 by apitoise         ###   ########.fr       */
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
		resultat.tmpidx = 0;
		while (data.str[data.pos])
		{
			while (data.str[data.pos] && data.str[data.pos] != '%')
				data.pos++;
			if (data.str[data.pos] == '%')
			{
				data.conv = data.str[data.pos + 1];
				printf("printftmp: %s\n", resultat.tmp);
				resultat.tmp = ft_tmp(data, &resultat);
				printf("printftmp: %s\n", resultat.tmp);
				resultat.res = ft_parsing(va, data, resultat);
				data.pos += 2;
			}
		}
	}
	ft_putstr(resultat.res);
	return (0);
}
