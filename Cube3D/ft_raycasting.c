/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:15:34 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/23 15:15:35 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_raycasting(t_allstruct *all)
{
	all->algo.x = -1;
	init_datastruct(&all->data);
	while (++all->algo.x < all->data.width)
	{
		init_loop_algostruct(all);
		all->algo.lineHeight = (int)(all->data.height / all->algo.perpWallDist);
		all->algo.drawStart = -all->algo.lineHeight / 2 + all->data.height / 2;
		if (all->algo.drawStart < 0)
			all->algo.drawStart = 0;
		all->algo.drawEnd = all->algo.lineHeight / 2 + all->data.height / 2;
		if (all->algo.drawEnd >= all->data.height)
			all->algo.drawEnd = all->data.height - 1;
		ft_painting(all);
	}
	mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
		all->data.img_ptr, 0, 0);
	mlx_destroy_image(all->data.mlx_ptr, all->data.img_ptr);
}