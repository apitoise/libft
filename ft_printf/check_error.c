/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:14:13 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/01 16:29:51 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_error(const char *str, int pos)
{
	if (str[pos + 1] == 'c' || str[pos + 1] == 'd' || str[pos + 1] == 's' ||
		str[pos + 1] == 'i' || str[pos + 1] == 'p' || str[pos + 1] == 'u' ||
		str[pos + 1] == 'x' || str[pos + 1] == 'X' || str[pos + 1] == '%')
		return (0);
	else
		return (-1);
}
