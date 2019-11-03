/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:04:48 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/03 18:06:12 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pf_c(va_list va, t_data data, t_resultat *resultat)
{
	char	new[2];

	new[0] = va_arg(va, int);
	new[1] = '\0';
	if (!(resultat->res = ft_strjoin(resultat->res, new)))
		return (NULL);
	return (resultat->res);
}
