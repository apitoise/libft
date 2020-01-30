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

/*void		init_tex(t_allstruct *all)
{
	int 	w;
	int 	h;

	all->tex[0].teximg = mlx_xpm_file_to_image(all->data.mlx_ptr,
		"textures/wood.xpm", &w, &h);
	all->tex[0].data = mlx_get_data_addr(all->tex[0].teximg,
		&all->tex[0].bpp, &all->tex[0].size_line, &all->tex[0].endian);
	all->tex[1].teximg = mlx_xpm_file_to_image(all->data.mlx_ptr,
		"textures/redbrick.xpm", &w, &h);
	all->tex[1].data = mlx_get_data_addr(all->tex[1].teximg,
		&all->tex[1].bpp, &all->tex[1].size_line, &all->tex[1].endian);
	all->tex[2].teximg = mlx_xpm_file_to_image(all->data.mlx_ptr,
		"textures/purplestone.xpm", &w, &h);
	all->tex[2].data = mlx_get_data_addr(all->tex[2].teximg,
		&all->tex[2].bpp, &all->tex[2].size_line, &all->tex[2].endian);
	all->tex[3].teximg = mlx_xpm_file_to_image(all->data.mlx_ptr,
		"textures/mossy.xpm", &w, &h);
	all->tex[3].data = mlx_get_data_addr(all->tex[3].teximg,
		&all->tex[3].bpp, &all->tex[3].size_line, &all->tex[3].endian);
}*/

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