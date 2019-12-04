/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop_algostruct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:27:26 by apitoise          #+#    #+#             */
/*   Updated: 2019/12/04 16:33:52 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_loop_algostruct(t_algo *algo, t_data *data)
{
	algo->cameraX = 2 * algo->x / (double)data->width - 1;
	algo->rayDirX = algo->dirX + algo->planeX * algo->cameraX;
	algo->rayDirY = algo->dirY + algo->planeY * algo->cameraX;
	algo->mapX = (int)algo->posX;
	algo->mapY = (int)algo->posY;
	algo->deltaDistX = fabs(1 / algo->rayDirX);
	algo->deltaDistY = fabs(1 / algo->rayDirY);
	algo->hit = 0;
}
