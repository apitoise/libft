/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:56:29 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/15 16:09:48 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_digitflags(va_list va, const char *str, int pos, t_flags *flags)
{
	flags->width = ft_atoi(&str[pos]);
	while (ft_isdigit(str[pos]))
		pos++;
	return (pos);
}			
