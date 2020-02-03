/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_algostruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:09:53 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/23 14:18:43 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		init_winstruct(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
		data->width, data->height, "Cube3D");
}

void		init_datastruct(t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr,
		data->width, data->height);
	data->data_ptr = (int *)mlx_get_data_addr(data->img_ptr,
		&data->bits, &data->size_line, &data->endian);
}

void		init_algostruct(t_allstruct *all)
{
	all->algo.move_up = 0;
	all->algo.move_down = 0;
	all->algo.move_right = 0;
	all->algo.move_left = 0;
	all->algo.rot_left = 0;
	all->algo.rot_right = 0;
	all->algo.posX = 6;
	all->algo.posY = 3;
	all->algo.dirX = -1;
	all->algo.dirY = 0;
	all->algo.planeX = 0;
	all->algo.planeY = 0.66;
	all->algo.ms = 0.05;
	all->algo.rs = 0.05;
}

void		init_struct(t_allstruct *all)
{
	init_winstruct(&all->data);
	init_algostruct(all);
}