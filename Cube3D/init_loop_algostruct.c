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

void	algo_init(t_algo *algo)
{
	if (algo->rayDirX < 0)
	{
		algo->stepX = -1;
		algo->sideDistX = (algo->rayPosX - algo->mapX)
			* algo->deltaDistX;
	}
	else
	{
		algo->stepX = 1;
		algo->sideDistX = (algo->mapX + 1.0 - algo->rayPosX)
			* algo->deltaDistX;
	}
	if (algo->rayDirY < 0)
	{
		algo->stepY = -1;
		algo->sideDistY = (algo->rayPosY - algo->mapY)
			* algo->deltaDistY;
	}
	else
	{
		algo->stepY = 1;
		algo->sideDistY = (algo->mapY + 1.0 - algo->rayPosY)
			* algo->deltaDistY;
	}
}

void	ray_algo(t_algo *algo)
{
	algo->hit = 0;
	while (algo->hit == 0)
	{
		if (algo->sideDistX < algo->sideDistY)
		{
			if (algo->rayDirX < 0)
				algo->side = 0;
			else if (algo->rayDirX > 0)
				algo->side = 1;
			algo->sideDistX += algo->deltaDistX;
			algo->mapX += algo->stepX;
		}
		else
		{
			if (algo->rayDirY < 0)
				algo->side = 2;
			else if (algo->rayDirY > 0)
				algo->side = 3;
			algo->sideDistY += algo->deltaDistY;
			algo->mapY += algo->stepY;
		}
		if (worldMap[algo->mapX][algo->mapY] > 0)
			algo->hit = 1;
		if (algo->side == 0 || algo->side == 1)
			algo->perpWallDist = (algo->mapX - algo->posX
				+ (1 - algo->stepX) / 2) / algo->rayDirX;
		else
			algo->perpWallDist = (algo->mapY - algo->posY
				+ (1 - algo->stepY) / 2) / algo->rayDirY;
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
	algo_init(&all->algo);
	ray_algo(&all->algo);
}
