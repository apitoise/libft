/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop_algostruct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:27:26 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/21 17:27:12 by apitoise         ###   ########.fr       */
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
		algo->stepX = -1;
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
		algo->stepY = -1;
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
			algo->sideDistX += algo->deltaDistX;
			algo->mapX += algo->stepX;
			algo->side = 0;
		}
		else
		{
			algo->sideDistY += algo->deltaDistY;
			algo->mapY += algo->stepY;
			algo->side = 1;
		}
		if (worldMap[algo->mapX][algo->mapY] > 0)
			algo->hit = 1;
	}
}

void	init_loop_algostruct(t_algo *algo)
{
	algo->cameraX = 2 * algo->x / (double)WINX - 1;
	algo->rayPosX = algo->posX;
	algo->rayPosY = algo->posY;
	algo->rayDirX = algo->dirX + algo->planeX * algo->cameraX;
	algo->rayDirY = algo->dirY + algo->planeY * algo->cameraX;
	algo->mapX = (int)algo->posX;
	algo->mapY = (int)algo->posY;
	algo->deltaDistX = fabs(1 / algo->rayDirX);
	algo->deltaDistY = fabs(1 / algo->rayDirY);
	algo_init(algo);
	ray_algo(algo);
	if (algo->side == 0)
		algo->perpWallDist = (algo->mapX - algo->rayPosX +
			(1 - algo->stepX) / 2) / algo->rayDirX;
	else
		algo->perpWallDist = (algo->mapY - algo->rayPosY +
			(1 - algo->stepY) / 2) / algo->rayDirY;
}
