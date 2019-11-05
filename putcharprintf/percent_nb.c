/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:14:53 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/05 15:38:01 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		percent_nb(char *str)
{
	int		pos;
	int		num;

	pos = 0;
	num = 0;
	while (str[pos])
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
