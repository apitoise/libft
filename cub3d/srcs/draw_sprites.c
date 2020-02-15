/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:12:04 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/15 13:34:02 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

static void	init_sprites_struct(t_allstruct *all, int i)
{
	all->algo.s_x = all->sprt[i].posx - all->algo.posx + 0.5;
	all->algo.s_y = all->sprt[i].posy - all->algo.posy + 0.5;
	all->algo.inv = 1.0 / (all->algo.planex * all->algo.diry
		- all->algo.dirx * all->algo.planey);
	all->algo.trans_x = all->algo.inv * (all->algo.diry * all->algo.s_x
		- all->algo.dirx * all->algo.s_y);
	all->algo.trans_y = all->algo.inv * (-all->algo.planey * all->algo.s_x
		+ all->algo.planex * all->algo.s_y);
	all->algo.screen_x = (int)((all->data.width / 2)
		* (1 + all->algo.trans_x / all->algo.trans_y));
	all->algo.s_h = abs((int)(all->data.height / (all->algo.trans_y)));
	all->algo.start_y = -all->algo.s_h / 2 + all->data.height / 2;
	if (all->algo.start_y < 0)
		all->algo.start_y = 0;
	all->algo.end_y = all->algo.s_h / 2 + all->data.height / 2;
	if (all->algo.end_y >= all->data.height)
		all->algo.end_y = all->data.height - 1;
	all->algo.s_w = abs((int)(all->data.height / (all->algo.trans_y)));
	all->algo.start_x = -all->algo.s_w / 2 + all->algo.screen_x;
	if (all->algo.start_x < 0)
		all->algo.start_x = 0;
	all->algo.end_x = all->algo.s_w / 2 + all->algo.screen_x;
	if (all->algo.end_x >= all->data.width)
		all->algo.end_x = all->data.width - 1;
}

static void	print_sprites(t_allstruct *all, int i)
{
	int		y;
	int		d;
	int		color;

	all->algo.s_tex_x = (int)(256 * (all->algo.stripe - (-all->algo.s_w
		/ 2 + all->algo.screen_x)) * all->sprt[i].w
		/ all->algo.s_w) / 256;
	if (all->algo.trans_y > 0 && all->algo.stripe > 0 && all->algo.stripe
		< all->data.width && all->algo.trans_y
		< all->algo.zbuff[all->algo.stripe])
	{
		y = all->algo.start_y;
		while (y < all->algo.end_y)
		{
			d = (y) * 256 - all->data.height * 128 + all->algo.s_h * 128;
			all->algo.s_tex_y = ((d * all->sprt[i].h)
				/ all->algo.s_h) / 256;
			color = *(all->sprt[i].data + (all->sprt[i].w *
				all->algo.s_tex_y) + all->algo.s_tex_x);
			if ((color & 0x00FFFFFF) != 0)
				*(all->data.data_ptr + (all->data.width * y)
					+ all->algo.stripe) = color;
			y++;
		}
	}
}

static void	swap(t_allstruct *all, int i, int j)
{
	t_sprt	tmp;

	tmp = all->sprt[i];
	all->sprt[i] = all->sprt[j];
	all->sprt[j] = tmp;
}

void		sort_sprites(t_allstruct *all)
{
	int gap;
	int swapped;
	int i;

	gap = all->map.nb_sprt;
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
		while (i < all->map.nb_sprt - gap)
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

void		draw_sprites(t_allstruct *all)
{
	int		i;

	get_sprite(all);
	if (all->sprterror == 1)
		return ;
	sort_sprites(all);
	i = 0;
	while (i < all->map.nb_sprt)
	{
		init_sprites_struct(all, i);
		all->algo.stripe = all->algo.start_x;
		while (all->algo.stripe < all->algo.end_x)
		{
			print_sprites(all, i);
			all->algo.stripe++;
		}
		i++;
	}
	free(all->sprt);
}
