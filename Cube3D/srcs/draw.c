/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:35:47 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/07 18:51:58 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

void	pick_tex(t_allstruct *all, int d, int *color)
{
	if (all->algo.side == 0)
	{
		all->algo.texY[0] = ((d * all->tex[0].h) / all->algo.lineHeight) / 256;
		*color = *(all->tex[0].data + (all->tex[0].h * all->algo.texY[0])
			+ all->algo.texX[0]);
	}
	else if (all->algo.side == 1)
	{
		all->algo.texY[1] = ((d * all->tex[1].h) / all->algo.lineHeight) / 256;
		*color = *(all->tex[1].data + (all->tex[1].h * all->algo.texY[1])
			+ all->algo.texX[1]);
	}
	else if (all->algo.side == 2)
	{
		all->algo.texY[2] = ((d * all->tex[2].h) / all->algo.lineHeight) / 256;
		*color = *(all->tex[2].data + (all->tex[2].h * all->algo.texY[2])
			+ all->algo.texX[2]);
	}
	else if (all->algo.side == 3)
	{
		all->algo.texY[3] = ((d * all->tex[3].h) / all->algo.lineHeight) / 256;
		*color = *(all->tex[3].data + (all->tex[3].h * all->algo.texY[3])
			+ all->algo.texX[3]);
	}
}

void	draw_sky(t_allstruct *all)
{
	int 	y;

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

void	draw_tex_wall(t_allstruct *all)
{
	int 	j;
	int 	d;
	int 	color;

	j = all->algo.drawStart;
	while (j < all->algo.drawEnd)
	{
		d = j * 256 - all->data.height * 128 + all->algo.lineHeight * 128;
		pick_tex(all, d, &color);
		*(all->data.data_ptr + (all->data.width * j)
			+ all->algo.x) = color;	
		j++;
	}
}

void	ft_painting(t_allstruct *all)
{
	int 	i;

	i = 0;
	while (i < 4)
	{
		all->algo.texX[i] = (int)(all->algo.wallX * (double)(all->tex[i].w));
		all->algo.texX[i] = all->tex[i].w - all->algo.texX[i] - 1;
		i++;
	}
	draw_sky(all);
	draw_floor(all);
	draw_tex_wall(all);
}
