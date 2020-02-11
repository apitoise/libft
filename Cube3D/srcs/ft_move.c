/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:43:20 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/04 17:03:12 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

static void		ft_moveupndown(t_allstruct *all)
{
	if (all->algo.move_up == 1)
	{
		if (all->map.map[(int)(all->algo.posX + all->algo.dirX * all->algo.ms)]
				[(int)(all->algo.posY)] != 1)
			all->algo.posX += all->algo.dirX * all->algo.ms;
		if (all->map.map[(int)(all->algo.posX)]
				[(int)(all->algo.posY + all->algo.dirY * all->algo.ms)] != 1)
			all->algo.posY += all->algo.dirY * all->algo.ms;
	}
	else if (all->algo.move_down == 1)
	{
		if (all->map.map[(int)(all->algo.posX - all->algo.dirX * all->algo.ms)]
				[(int)(all->algo.posY)] != 1)
			all->algo.posX -= all->algo.dirX * all->algo.ms;
		if (all->map.map[(int)(all->algo.posX)]
				[(int)(all->algo.posY - all->algo.dirY * all->algo.ms)] != 1)
			all->algo.posY -= all->algo.dirY * all->algo.ms;
	}
}

static void		ft_moveside(t_allstruct *all)
{
	if (all->algo.move_left == 1)
	{
		if (all->map.map[(int)(all->algo.posX - all->algo.planeX
			* all->algo.ms)][(int)(all->algo.posY)] != 1)
			all->algo.posX -= all->algo.planeX * all->algo.ms;
		if (all->map.map[(int)(all->algo.posX)]
				[(int)(all->algo.posY - all->algo.planeY * all->algo.ms)] != 1)
			all->algo.posY -= all->algo.planeY * all->algo.ms;
	}
	else if (all->algo.move_right == 1)
	{
		if (all->map.map[(int)(all->algo.posX + all->algo.planeX
			* all->algo.ms)][(int)(all->algo.posY)] != 1)
			all->algo.posX += all->algo.planeX * all->algo.ms;
		if (all->map.map[(int)(all->algo.posX)]
				[(int)(all->algo.posY + all->algo.planeY * all->algo.ms)] != 1)
			all->algo.posY += all->algo.planeY * all->algo.ms;
	}
}

static void		ft_rotation(t_allstruct *all)
{
	if (all->algo.rot_right == 1)
	{
		all->algo.oldDirX = all->algo.dirX;
		all->algo.dirX = all->algo.dirX * cos(-all->algo.rs)
			- all->algo.dirY * sin(-all->algo.rs);
		all->algo.dirY = all->algo.oldDirX * sin(-all->algo.rs)
			+ all->algo.dirY * cos(-all->algo.rs);
		all->algo.oldPlaneX = all->algo.planeX;
		all->algo.planeX = all->algo.planeX * cos(-all->algo.rs)
			- all->algo.planeY * sin(-all->algo.rs);
		all->algo.planeY = all->algo.oldPlaneX * sin(-all->algo.rs)
			+ all->algo.planeY * cos(-all->algo.rs);
	}
	else if (all->algo.rot_left == 1)
	{
		all->algo.oldDirX = all->algo.dirX;
		all->algo.dirX = all->algo.dirX * cos(all->algo.rs)
			- all->algo.dirY * sin(all->algo.rs);
		all->algo.dirY = all->algo.oldDirX * sin(all->algo.rs)
			+ all->algo.dirY * cos(all->algo.rs);
		all->algo.oldPlaneX = all->algo.planeX;
		all->algo.planeX = all->algo.planeX * cos(all->algo.rs)
			- all->algo.planeY * sin(all->algo.rs);
		all->algo.planeY = all->algo.oldPlaneX * sin(all->algo.rs)
			+ all->algo.planeY * cos(all->algo.rs);
	}
}

int				ft_move(t_allstruct *all)
{
	if (all->algo.move_up == 1 || all->algo.move_down == 1)
		ft_moveupndown(all);
	if (all->algo.move_right == 1 || all->algo.move_left == 1)
		ft_moveside(all);
	if (all->algo.rot_left == 1 || all->algo.rot_right == 1)
		ft_rotation(all);
	ft_raycasting(all);
	return (0);
}