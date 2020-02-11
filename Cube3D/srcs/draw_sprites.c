/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:12:04 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/07 22:12:10 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

static void	init_sprites_struct(t_allstruct *all, int i)
{
	all->algo.s_x = all->sprt[i].posX - all->algo.posX;
	all->algo.s_y = all->sprt[i].posY - all->algo.posY;
	all->algo.inv = 1.0 / (all->algo.planeX * all->algo.dirY
		- all->algo.dirX * all->algo.planeY);
	all->algo.transX = all->algo.inv * (all->algo.dirY * all->algo.s_x
		- all->algo.dirX * all->algo.s_y);
	all->algo.transY = all->algo.inv * (-all->algo.planeY * all->algo.s_x
		+ all->algo.planeX * all->algo.s_y);
	all->algo.s_screenX = (int)((all->data.width / 2)
		* (1 + all->algo.transX / all->algo.transY));
	all->algo.s_h = abs((int)(all->data.height / (all->algo.transY)));
	all->algo.dStartY= -all->algo.s_h / 2 + all->data.height / 2;
	if (all->algo.dStartY < 0)
		all->algo.dStartY = 0;
	all->algo.dEndY = all->algo.s_h / 2 + all->data.height / 2;
	if (all->algo.dEndY >= all->data.height)
		all->algo.dEndY = all->data.height - 1;
	all->algo.s_w = abs((int)(all->data.height / (all->algo.transY)));
	all->algo.dStartX = -all->algo.s_w / 2 + all->algo.s_screenX;
	if (all->algo.dStartX < 0)
		all->algo.dStartX = 0;
	all->algo.dEndX = all->algo.s_w / 2 + all->algo.s_screenX;
	if (all->algo.dEndX >= all->data.width)
		all->algo.dEndX = all->data.width - 1;
}

static void	print_sprites(t_allstruct *all, int i)
{
	int 	y;
	int 	d;
	int 	color;

	all->algo.s_texX = (int)(256 * (all->algo.stripe - (-all->algo.s_w
		/ 2 + all->algo.s_screenX)) * all->sprt[i].w
		/ all->algo.s_w) / 256;
	if (all->algo.transY > 0 && all->algo.stripe > 0 && all->algo.stripe
		< all->data.width && all->algo.transY
		< all->algo.zBuff[all->algo.stripe])
	{
		y = all->algo.dStartY;
		while (y < all->algo.dEndY)
		{
			d = (y) * 256 - all->data.height * 128 + all->algo.s_h * 128;
			all->algo.s_texY = ((d * all->sprt[i].h)
				/ all->algo.s_h) / 256;
			color = *(all->sprt[i].data + (all->sprt[i].w *
				all->algo.s_texY) + all->algo.s_texX);
			if ((color & 0x00FFFFFF) != 0)
				*(all->data.data_ptr + (all->data.width * y)
					+ all->algo.stripe) = color;
			y++;
		}
	}
}

static void	swap(t_allstruct *all, int i, int j)
{
	t_sprt 	tmp;

	tmp = all->sprt[i];
	all->sprt[i] = all->sprt[j];
	all->sprt[j] = tmp;
}

void		sort_sprites(t_allstruct *all)
{
	int gap;
	int swapped;
	int i;

	gap = all->map.nbSprites;
	swapped = 0;
	while (gap > 1 || swapped)
	{
		gap = (gap * 10) / 13;
		if (gap == 9 || gap == 10)
			gap = 11;
		if (gap < 1)
			gap = 1;
		swapped = 0;
		i = 0;
		while (i < all->map.nbSprites - gap)
		{
			if (all->sprt[i].distance < all->sprt[i + gap].distance)
			{
				swap(all, i, i + gap);
				swapped = 1;
			}
			i++;
		}
	}
}

void	draw_sprites(t_allstruct *all)
{
	int		i;

	get_sprite(all);
	if (all->sprtError == 1)
		return ;
	sort_sprites(all);
	i = 0;
	while (i < all->map.nbSprites)
	{
		init_sprites_struct(all, i);
		all->algo.stripe = all->algo.dStartX;
		while (all->algo.stripe < all->algo.dEndX)
		{
			print_sprites(all, i);
			all->algo.stripe++;
		}
		i++;
	}
}