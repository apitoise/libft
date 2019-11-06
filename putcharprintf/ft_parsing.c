/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:50:06 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/06 17:10:49 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_parsing(va_list va, const char *str, int pos)
{
	if (str[pos + 1] == 'c')
		return (pf_c(va));
	if (str[pos + 1] == 'd' || str[pos + 1] == 'i')
		return (pf_id(va));
	if (str[pos + 1] == 'u')
		return (pf_u(va));
	if (str[pos + 1] == 's')
		return (pf_s(va));
	if (str[pos + 1] == 'p')
		return (pf_p(va));
	if (str[pos + 1] == 'x')
		return (pf_x(va));
	if (str[pos + 1] == 'X')
		return (pf_cx(va));
	if (str[pos + 1] == '%')
		return (pf_percent(va));
	else
		return (-1);
}
