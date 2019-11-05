/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:50:06 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/05 17:49:51 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_parsing(va_list va, const char *str, int pos)
{
	if (str[pos + 1] == 'c')
		return (pf_c(va));
	if (str[pos + 1] == 'd' || str[pos + 1] == 'i' || str[pos + 1] == 'u')
		return (pf_idu(va));
	if (str[pos + 1] == 's')
		return (pf_s(va));
//	if (resultat.res == 'p')
//		return (pf_p());
//	if (resultat.res == 'x')
//		return (pf_x());
//	if (resultat.res == 'X')
//		return (pf_cx());
	else
		return (-1);
}
