/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:50:06 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/13 17:23:32 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_parsing(va_list va, const char *str, int pos)
{
	t_flags		flags;

	init_struct(&flags);
	pos += 1;
	while (!(is_conv(str, pos)))
		pos = search_flags(va, str, pos, &flags);
	if (str[pos] == 'c')
		return (pf_c(va, pos, flags));
	if (str[pos] == 'd' || str[pos] == 'i')
		return (pf_id(va, pos, flags));
	if (str[pos] == 'u')
		return (pf_u(va, pos, flags));
	if (str[pos] == 's')
		return (pf_s(va, pos, flags));
	if (str[pos] == 'p')
		return (pf_p(va, pos, flags));
	if (str[pos] == 'x')
		return (pf_x(va, pos, flags));
	if (str[pos] == 'X')
		return (pf_cx(va, pos, flags));
	if (str[pos] == '%')
		return (pf_percent(va, pos, flags));
	return (-1);
}
