/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:15:34 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/12 15:32:40 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

static void	ray_loop(t_allstruct *all)
{
	init_loop_algostruct(all);
	all->algo.line_h = (int)(all->data.height
		/ all->algo.wall_dist);
	all->algo.d_start = -(all->algo.line_h) / 2
		+ all->data.height / 2;
	if (all->algo.d_start < 0)
		all->algo.d_start = 0;
	all->algo.d_end = all->algo.line_h / 2 + all->data.height / 2;
	if (all->algo.d_end >= all->data.height)
		all->algo.d_end = all->data.height - 1;
	if (all->algo.side == 0 || all->algo.side == 1)
		all->algo.wall_x = all->algo.posy + all->algo.wall_dist
			* all->algo.ray_dy;
	else
		all->algo.wall_x = all->algo.posx + all->algo.wall_dist
			* all->algo.ray_dx;
	all->algo.wall_x -= floor((all->algo.wall_x));
	ft_painting(all);
	all->algo.zbuff[all->algo.x] = all->algo.wall_dist;
}

void		ft_raycasting(t_allstruct *all)
{
	all->algo.x = -1;
	init_datastruct(&all->data);
	if (!(all->algo.zbuff = malloc(sizeof(double) * all->data.width)))
		return ;
	while (++all->algo.x < all->data.width)
		ray_loop(all);
	if (all->map.nb_sprt > 0)
		draw_sprites(all);
	free(all->algo.zbuff);
	if (all->sprterror == 1)
		return ;
	mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
		all->data.img_ptr, 0, 0);
	mlx_destroy_image(all->data.mlx_ptr, all->data.img_ptr);
}
