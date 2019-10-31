/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:42:26 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/31 17:00:21 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_error(const char *str, int pos)
{
	if (str[pos + 2] != ' ')
		return (-1);
	if (str[pos + 1] == 'c' || str[pos + 1] == 'd' || str[pos + 1] == 's' ||
		str[pos + 1] == 'i' || str[pos + 1] == 'p' || str[pos + 1] == 'u' ||
		str[pos + 1] == 'x' || str[pos + 1] == 'X' || str[pos + 1] == '%')
		return (0);
	else
		return (-1);
}

int		percent_nb(const char *str)
{
	int		pos;
	int 	num;

	pos = 0;
	num = 0;
	while(str[pos])
	{
		if (str[pos] == '%')
		{
			if (check_error(str, pos) == -1)
				return (-1);
			if (str[pos + 1] == '%')
				pos++;
			num++;
		}
		pos++;
	}
	return (num);
}

int		ft_printf(const char *str, ...)
{
	int			num;
	int			count;
	va_list		va;

	num = percent_nb(str);
	if (num < 0)
		return (-1);
	va_start(va, num);
	while (count < num)
	{
		va_arg(va, char);
		count++;
	}
	printf("nb = %d\n", count);
	va_end(va);
	return (0);
}
