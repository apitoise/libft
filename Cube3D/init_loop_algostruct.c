/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop_algostruct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:27:26 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/23 15:15:42 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	algo_init(t_allstruct *all)
{
	if (all->algo.rayDirX < 0)
	{
		all->algo.stepX = -1;
		all->algo.sideDistX = (all->algo.rayPosX - all->algo.mapX)
			* all->algo.deltaDistX;
	}
	else
	{
		all->algo.stepX = 1;
		all->algo.sideDistX = (all->algo.mapX + 1.0 - all->algo.rayPosX)
			* all->algo.deltaDistX;
	}
	if (all->algo.rayDirY < 0)
	{
		all->algo.stepY = -1;
		all->algo.sideDistY = (all->algo.rayPosY - all->algo.mapY)
			* all->algo.deltaDistY;
	}
	else
	{
		all->algo.stepY = 1;
		all->algo.sideDistY = (all->algo.mapY + 1.0 - all->algo.rayPosY)
			* all->algo.deltaDistY;
	}
}

void	ray_algo(t_allstruct *all)
{
	all->algo.hit = 0;
	while (all->algo.hit == 0)
	{
		if (all->algo.sideDistX < all->algo.sideDistY)
		{
			if (all->algo.rayDirX < 0)
				all->algo.side = 0;
			else if (all->algo.rayDirX > 0)
				all->algo.side = 1;
			all->algo.sideDistX += all->algo.deltaDistX;
			all->algo.mapX += all->algo.stepX;
		}
		else
		{
			if (all->algo.rayDirY < 0)
				all->algo.side = 2;
			else if (all->algo.rayDirY > 0)
				all->algo.side = 3;
			all->algo.sideDistY += all->algo.deltaDistY;
			all->algo.mapY += all->algo.stepY;
		}
		if (all->map.map[all->algo.mapX][all->algo.mapY] > 0)
			all->algo.hit = 1;
		if (all->algo.side == 0 || all->algo.side == 1)
			all->algo.perpWallDist = (all->algo.mapX - all->algo.posX
				+ (1 - all->algo.stepX) / 2) / all->algo.rayDirX;
		else
			all->algo.perpWallDist = (all->algo.mapY - all->algo.posY
				+ (1 - all->algo.stepY) / 2) / all->algo.rayDirY;
	}
}

void	init_loop_algostruct(t_allstruct *all)
{
	all->algo.cameraX = 2 * all->algo.x / (double)all->data.width - 1;
	all->algo.rayPosX = all->algo.posX;
	all->algo.rayPosY = all->algo.posY;
	all->algo.rayDirX = all->algo.dirX + all->algo.planeX * all->algo.cameraX;
	all->algo.rayDirY = all->algo.dirY + all->algo.planeY * all->algo.cameraX;
	all->algo.mapX = (int)all->algo.posX;
	all->algo.mapY = (int)all->algo.posY;
	all->algo.deltaDistX = fabs(1 / all->algo.rayDirX);
	all->algo.deltaDistY = fabs(1 / all->algo.rayDirY);
	algo_init(all);
	ray_algo(all);
}
