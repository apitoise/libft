/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop_algostruct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:27:26 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/12 15:56:17 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

void		algo_init(t_allstruct *all)
{
	if (all->algo.ray_dx < 0)
	{
		all->algo.step_x = -1;
		all->algo.side_dx = (all->algo.ray_px - all->algo.mapx)
			* all->algo.delta_dx;
	}
	else
	{
		all->algo.step_x = 1;
		all->algo.side_dx = (all->algo.mapx + 1.0 - all->algo.ray_px)
			* all->algo.delta_dx;
	}
	if (all->algo.ray_dy < 0)
	{
		all->algo.step_y = -1;
		all->algo.side_dy = (all->algo.ray_py - all->algo.mapy)
			* all->algo.delta_dy;
	}
	else
	{
		all->algo.step_y = 1;
		all->algo.side_dy = (all->algo.mapy + 1.0 - all->algo.ray_py)
			* all->algo.delta_dy;
	}
}

static void	ray_algo_bis(t_allstruct *all)
{
	if (all->map.map[all->algo.mapx][all->algo.mapy] == 1)
		all->algo.hit = 1;
	if (all->algo.side == 0 || all->algo.side == 1)
		all->algo.wall_dist = (all->algo.mapx - all->algo.posx
		+ (1 - all->algo.step_x) / 2) / all->algo.ray_dx;
	else
		all->algo.wall_dist = (all->algo.mapy - all->algo.posy
			+ (1 - all->algo.step_y) / 2) / all->algo.ray_dy;
}

void		ray_algo(t_allstruct *all)
{
	all->algo.hit = 0;
	while (all->algo.hit == 0)
	{
		if (all->algo.side_dx < all->algo.side_dy)
		{
			if (all->algo.ray_dx < 0)
				all->algo.side = 0;
			else if (all->algo.ray_dx > 0)
				all->algo.side = 1;
			all->algo.side_dx += all->algo.delta_dx;
			all->algo.mapx += all->algo.step_x;
		}
		else
		{
			if (all->algo.ray_dy < 0)
				all->algo.side = 2;
			else if (all->algo.ray_dy > 0)
				all->algo.side = 3;
			all->algo.side_dy += all->algo.delta_dy;
			all->algo.mapy += all->algo.step_y;
		}
		ray_algo_bis(all);
	}
}

void		init_loop_algostruct(t_allstruct *all)
{
	all->algo.cam_x = 2 * all->algo.x / (double)all->data.width - 1;
	all->algo.ray_px = all->algo.posx;
	all->algo.ray_py = all->algo.posy;
	all->algo.ray_dx = all->algo.dirx + all->algo.planex * all->algo.cam_x;
	all->algo.ray_dy = all->algo.diry + all->algo.planey * all->algo.cam_x;
	all->algo.mapx = (int)all->algo.posx;
	all->algo.mapy = (int)all->algo.posy;
	all->algo.delta_dx = fabs(1 / all->algo.ray_dx);
	all->algo.delta_dy = fabs(1 / all->algo.ray_dy);
	algo_init(all);
	ray_algo(all);
}
