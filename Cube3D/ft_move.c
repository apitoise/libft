/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:43:20 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/25 11:17:32 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void		ft_moveupndown(t_algo *algo)
{
	if (algo->move_up == 1)
	{
		if (worldMap[(int)(algo->posX + algo->dirX * algo->ms)]
				[(int)(algo->posY)] == 0)
			algo->posX += algo->dirX * algo->ms;
		if (worldMap[(int)(algo->posX)]
				[(int)(algo->posY + algo->dirY * algo->ms)] == 0)
			algo->posY += algo->dirY * algo->ms;
	}
	else if (algo->move_down == 1)
	{
		if (worldMap[(int)(algo->posX + algo->dirX * algo->ms)]	
				[(int)(algo->posY)] == 0)
			algo->posX -= algo->dirX * algo->ms;
		if (worldMap[(int)(algo->posX)]
				[(int)(algo->posY + algo->dirY * algo->ms)] == 0)
			algo->posY -= algo->dirY * algo->ms;
	}
}

static void		ft_moveside(t_algo *algo)
{
	if (algo->move_right == 1)
	{
		if (worldMap[(int)(algo->posX + algo->dirY * algo->ms)]
				[(int)(algo->posY)] == 0)
			algo->posX -= algo->dirY * algo->ms;
		if (worldMap[(int)(algo->posX)]
				[(int)(algo->posY + algo->dirX * algo->ms)] == 0)
			algo->posY -= algo->dirX * algo->ms;
	}
	else if (algo->move_left == 1)
	{
		if (worldMap[(int)(algo->posX + algo->dirY * algo->ms)]
				[(int)(algo->posY)] == 0)
			algo->posX += algo->dirY * algo->ms;
		if (worldMap[(int)(algo->posX)]
				[(int)(algo->posY + algo->dirX * algo->ms)] == 0)
			algo->posY += algo->dirX * algo->ms;
	}
}

static void		ft_rotation(t_algo *algo)
{
	if (algo->rot_right == 1)
	{
		algo->oldDirX = algo->dirX;
		algo->dirX = algo->dirX * cos(-algo->rs) - algo->dirY * sin(-algo->rs);
		algo->dirY = algo->oldDirX * sin(-algo->rs) + algo->dirY * cos(-algo->rs);
		algo->oldPlaneX = algo->planeX;
		algo->planeX = algo->planeX * cos(-algo->rs) - algo->planeY * sin(-algo->rs);
		algo->planeY = algo->oldPlaneX * sin(-algo->rs)
			+ algo->planeY * cos(-algo->rs);
	}
	else if (algo->rot_left == 1)
	{
			algo->oldDirX = algo->dirX;
		algo->dirX = algo->dirX * cos(algo->rs) - algo->dirY * sin(algo->rs);
		algo->dirY = algo->oldDirX * sin(algo->rs) + algo->dirY * cos(algo->rs);
		algo->oldPlaneX = algo->planeX;
		algo->planeX = algo->planeX * cos(algo->rs) - algo->planeY * sin(algo->rs);
		algo->planeY = algo->oldPlaneX * sin(algo->rs)
			+ algo->planeY * cos(algo->rs);
	}
}

int		ft_move(t_twostruct *ts)
{
	if (ts->algo.move_up == 1 || ts->algo.move_down == 1)
		ft_moveupndown(&ts->algo);
	if (ts->algo.move_right == 1 || ts->algo.move_left == 1)
		ft_moveside(&ts->algo);
	if (ts->algo.rot_left == 1 || ts->algo.rot_right == 1)
		ft_rotation(&ts->algo);
	ft_raycasting(&ts->algo, &ts->data);
	return (0);
}
