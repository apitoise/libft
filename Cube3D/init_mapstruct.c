/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapstruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:09:42 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/31 19:09:45 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_mapstruct(t_allstruct *all)
{
	all->map.first = 0;
	all->map.height = 0;
	all->map.lenerror = 0;
	all->map.spawn = 0;
}