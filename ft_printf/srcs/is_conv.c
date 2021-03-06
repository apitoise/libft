/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:30:03 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/21 18:01:41 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../Libft/libft.h"

int		is_conv(const char *str, int pos)
{
	if (str[pos] == 'c' || str[pos] == 'd' || str[pos] == 'i'
		|| str[pos] == 'u' || str[pos] == 's' || str[pos] == 'p'
		|| str[pos] == 'c' || str[pos] == 'X' || str[pos] == '%'
		|| str[pos] == 'x')
		return (1);
	else
		return (0);
}
