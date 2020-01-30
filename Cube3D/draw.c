/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:35:47 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/25 13:06:32 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_colors(t_allstruct *all)
{
	all->data.sky_color = 0x77b5fe;
	all->data.floor_color = 0x3a9d23;
	if (all->algo.side == 0)
		all->data.wall_color = 0xdd8800;
	else if (all->algo.side == 1)
		all->data.wall_color = 0x00FF00;
	else if (all->algo.side == 2)
		all->data.wall_color = 0xdd8800 / 2;
	else if (all->algo.side == 3)
		all->data.wall_color = 0xdd8800 / 4;
}

void	draw_sky(t_allstruct *all)
{
	int		y;

	y = 0;
	while (y < all->data.height / 2)
	{
		*(all->data.data_ptr + (all->data.width * y)
			+ all->algo.x) = all->data.sky_color;
		y++;
	}
}

void	draw_floor(t_allstruct *all)
{
	int		y;

	y = all->data.height / 2;
	while (y < all->data.height)
	{
		*(all->data.data_ptr + (all->data.width * y)
			+ all->algo.x) = all->data.floor_color;
		y++;
	}
}

void	draw_wall(t_allstruct *all)
{
	int		y;

	y = all->algo.drawStart;

	if (all->algo.x < all->data.width && y < all->data.height)
	{
		while (y < all->algo.drawEnd )
		{
			init_colors(all);
			*(all->data.data_ptr + (all->data.width * y)
				+ all->algo.x) = all->data.wall_color;
			y++;
		}
	}
}

void	ft_painting(t_allstruct *all)
{
		init_colors(all);
		draw_sky(all);
		draw_floor(all);
		draw_wall(all);
}
