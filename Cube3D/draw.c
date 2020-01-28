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

void	init_colors(t_algo *algo, t_data *data)
{
	data->sky_color = 0x77b5fe;
	data->floor_color = 0x3a9d23;
	if (algo->side == 0)
		data->wall_color = 0xdd8800;
//	else
//		data->wall_color = 0x00FF00;
	else if (algo->side == 1)
		data->wall_color = 0x00FF00;
	else if (algo->side == 2)
		data->wall_color = 0xdd8800 / 2;
	else if (algo->side == 3)
		data->wall_color = 0xdd8800 / 4;
}

void	draw_sky(t_algo *algo, t_data *data)
{
	int		y;

	y = 0;
	while (y < WINY / 2)
	{
		*(data->data_ptr + (WINX * y) + algo->x) = data->sky_color;
		y++;
	}
}

void	draw_floor(t_algo *algo, t_data *data)
{
	int		y;

	y = WINY / 2;
	while (y < WINY)
	{
		*(data->data_ptr + (WINX * y) + algo->x) = data->floor_color;
		y++;
	}
}

void	draw_wall(t_algo *algo, t_data *data)
{
	int		y;

	y = algo->drawStart;

	if (algo->x < WINX && y < WINY)
	{
		while (y < algo->drawEnd )
		{
			init_colors(algo, data);
			*(data->data_ptr + (WINX * y) + algo->x) = data->wall_color;
			y++;
		}
	}
}

void	ft_painting(t_algo *algo, t_data *data)
{
		init_colors(algo, data);
		draw_sky(algo, data);
		draw_floor(algo, data);
		draw_wall(algo, data);
}
