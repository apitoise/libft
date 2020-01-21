/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:43:20 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/21 17:56:25 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_moveup(t_algo *algo)
{
	if (worldMap[(int)(algo->posX + algo->dirX * algo->ms)]
			[(int)(algo->posY)] == 0)
		algo->posX += algo->dirX * algo->ms;
	if (worldMap[(int)(algo->posX)]
			[(int)(algo->posY + algo->dirY * algo->ms)] == 0)
		algo->posY += algo->dirY * algo->ms;
}

void	ft_movedown(t_algo *algo)
{
	if (worldMap[(int)(algo->posX + algo->dirX * algo->ms)]	
			[(int)(algo->posY)] == 0)
		algo->posX -= algo->dirX * algo->ms;
	if (worldMap[(int)(algo->posX)]
			[(int)(algo->posY + algo->dirY * algo->ms)] == 0)
		algo->posY -= algo->dirY * algo->ms;
}

void	ft_moveright(t_algo *algo)
{
	algo->oldDirX = algo->dirX;
	algo->dirX = algo->dirX * cos(-algo->rs) - algo->dirY * sin(-algo->rs);
	algo->dirY = algo->oldDirX * sin(-algo->rs) - algo->dirY * cos(-algo->rs);
	algo->oldPlaneX = algo->planeX;
	algo->planeX = algo->planeX * cos(-algo->rs) - algo->planeY * sin(-algo->rs);
	algo->planeY = algo->oldPlaneX * sin(-algo->rs)
		+ algo->planeY * cos(-algo->rs);
}

void	ft_moveleft(t_algo *algo)
{
	algo->oldDirX = algo->dirX;
	algo->dirX = algo->dirX * cos(algo->rs) - algo->dirY * sin(algo->rs);
	algo->dirY = algo->oldDirX * sin(algo->rs) - algo->dirY * cos(algo->rs);
	algo->oldPlaneX = algo->planeX;
	algo->planeX = algo->planeX * cos(algo->rs) - algo->planeY * sin(algo->rs);
	algo->planeY = algo->oldPlaneX * sin(algo->rs)
		+ algo->planeY * cos(algo->rs);
}

int		ft_move(t_twostruct *ts)
{
	if (ts->algo->move_up == 1)
		ft_moveup(ts->algo);
	if (ts->algo->move_down == 1)
		ft_movedown(ts->algo);
	if (ts->algo->move_left == 1)
		ft_moveleft(ts->algo);
	if (ts->algo->move_right == 1)
		ft_moveright(ts->algo);
	ft_raycasting(ts->algo, ts->data);
	printf("posX = %f, posY = %f\n", ts->algo->posX, ts->algo->posY);
	return (0);
}
