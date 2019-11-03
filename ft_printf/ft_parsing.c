/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:50:06 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/03 17:39:36 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_parsing(va_list va, t_data data, t_resultat resultat)
{
	if (data.conv == 'c')
		return (pf_c(va, data, &resultat));
//	if (resultat.res == 'd' || str[len + 1] == 'i')
//		return (pf_id());
//	if (resultat.res == 's')
//		return (pf_s());
//	if (resultat.res == 'p')
//		return (pf_p());
//	if (resultat.res == 'u')
//		return (pf_u());
//	if (resultat.res == 'x')
//		return (pf_x());
//	if (resultat.res == 'X')
//		return (pf_cx());
	else
		return (NULL);
}
