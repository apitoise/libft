/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:19:34 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/13 17:46:39 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		va;
	int			idx;

	va_start(va, str);
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
	va_end(va);
	return (0);
}
