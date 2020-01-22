/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_algostruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:09:53 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/22 14:55:03 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		init_winstruct(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINX, WINY, "Cube3D");
}

void		init_datastruct(t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, WINX, WINY);
	data->data_ptr = (int *)mlx_get_data_addr(data->img_ptr, &data->bits,
		&data->size_line, &data->endian);
}

void		init_algostruct(t_algo *algo)
{
	algo->move_up = 0;
	algo->move_down = 0;
	algo->move_right = 0;
	algo->move_left = 0;
	algo->echapkey = 0;
	algo->posX = 6;
	algo->posY = 3;
	algo->dirX = -1;
	algo->dirY = 0;
	algo->planeX = 0;
	algo->planeY = 0.66;
	algo->ms = 0.05;
	algo->rs = 0.05;
}

void		init_struct(t_algo *algo, t_data *data)
{
	init_winstruct(data);
	init_algostruct(algo);
//	algo->first = 1;
}
