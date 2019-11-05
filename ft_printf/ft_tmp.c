/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:32:28 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/05 15:20:45 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_tmp(t_data data, t_resultat *resultat)
{
	int		index;
	char	*tmptmp;

	if (resultat->tmp == NULL)
	{
		resultat->tmpidx = 1;
		ft_strlcpy(resultat->tmp, data.str, data.pos + 1);
	}
	else
	{
		printf("tmp: ?\n");
//		while (resultat->res[index])
//			index++;
//		tmptmp = ft_substr(data.str, index, (data.pos - index));
//		resultat->tmp = ft_strjoin(resultat->res, tmptmp);
	}
	printf("tmp: %s\n", resultat->tmp);
	return (resultat->tmp);
}
