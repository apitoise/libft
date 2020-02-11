/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapstruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:09:42 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/04 17:17:05 by apitoise         ###   ########.fr       */
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
	all->algo.dirX = -1;
	all->algo.dirY = 0;
	all->algo.planeX = 0;
	all->algo.planeY = 0.66;
	olddirx = all->algo.dirX;
	all->algo.dirX = all->algo.dirX * cos(deg)
		- all->algo.dirY * sin(deg);
	all->algo.dirY = olddirx * sin(deg) + all->algo.dirY * cos(deg);
	oldplanex = all->algo.planeX;
	all->algo.planeX = all->algo.planeX * cos(deg)
		- all->algo.planeY * sin(deg);
	all->algo.planeY = oldplanex * sin(deg)
		+ all->algo.planeY * cos(deg);
}

void	get_spawn(int mapnb, int x, int y, t_allstruct *all)
{
	if (mapnb == 8 || mapnb == 7 || mapnb == 6 || mapnb == 5)
	{
		get_dir(mapnb, all);
		all->algo.posX = x + 0.1;
		all->algo.posY = y + 0.1;
	}
}

void	init_mapstruct(t_allstruct *all)
{
	all->map.first = 0;
	all->map.height = 0;
	all->map.lenerror = 0;
	all->map.spawn = 0;
	all->map.argT = 0;
	all->map.argSO = 0;
	all->map.argNO = 0;
	all->map.argR = 0;
	all->map.argW = 0;
	all->map.argE = 0;
	all->map.nbSprites = 0;
	all->map.error = 0;
	all->texError = 0;
	all->sprtError = 0;
}