/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapstruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:09:42 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/15 13:58:20 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

void	get_dir(int mapnb, t_allstruct *all)
{
	double	deg;
	double	olddirx;
	double	oldplanex;

	if (mapnb == 5)
		deg = -(M_PI_2);
	if (mapnb == 6)
		deg = M_PI;
	if (mapnb == 7)
		deg = M_PI_2;
	if (mapnb == 8)
		deg = 0;
	all->algo.dirx = -1;
	all->algo.diry = 0;
	all->algo.planex = 0;
	all->algo.planey = 0.66;
	olddirx = all->algo.dirx;
	all->algo.dirx = all->algo.dirx * cos(deg)
		- all->algo.diry * sin(deg);
	all->algo.diry = olddirx * sin(deg) + all->algo.diry * cos(deg);
	oldplanex = all->algo.planex;
	all->algo.planex = all->algo.planex * cos(deg)
		- all->algo.planey * sin(deg);
	all->algo.planey = oldplanex * sin(deg)
		+ all->algo.planey * cos(deg);
}

void	get_spawn(int mapnb, int x, int y, t_allstruct *all)
{
	if (mapnb == 8 || mapnb == 7 || mapnb == 6 || mapnb == 5)
	{
		get_dir(mapnb, all);
		all->algo.posx = x + 0.1;
		all->algo.posy = y + 0.1;
	}
}

void	init_mapstruct(t_allstruct *all)
{
	all->map.first = 0;
	all->map.height = 0;
	all->map.lenerror = 0;
	all->map.spawn = 0;
	all->map.argt = 0;
	all->map.argso = 0;
	all->map.argno = 0;
	all->map.argr = 0;
	all->map.args = 0;
	all->map.argw = 0;
	all->map.arge = 0;
	all->map.argf = 0;
	all->map.argc = 0;
	all->map.argm = 0;
	all->map.line = 0;
	all->map.nb_sprt = 0;
	all->map.error = 0;
	all->texerror = 0;
	all->sprterror = 0;
	all->map.d = 0;
}
