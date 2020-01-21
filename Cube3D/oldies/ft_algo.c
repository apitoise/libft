/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:05:16 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/21 17:44:58 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "Libft/libft.h"

void	ft_painting(t_data *data, t_algo *algo)
{
	int			y;

	y = algo->drawStart;
	while (y < algo->drawEnd)
	{
		*(data->data_ptr + (data->width * y) + algo->x) = data->color;
		y++;
	}
}
		

int		ft_algo(t_algo *algo, t_data *data)
{
	if (algo->first == 0)
		init_struct(algo, data);
	algo->x = 0;
	while (algo->x < data->width)
	{
		init_loop_algostruct(algo, data);
		if (algo->rayDirX < 0)
		{
			algo->stepX = -1;
			algo->sideDistX = (algo->posX - algo->mapX) * algo->deltaDistX;
		}
		else
		{
			algo->stepX = 1;
			algo->sideDistX = (algo->mapX + 1.0 - algo->posX)
				* algo->deltaDistX;
		}
		if (algo->rayDirY < 0)
		{
			algo->stepY = -1;
			algo->sideDistY = (algo->posY - algo->mapY) * algo->deltaDistY;
		}
		else
		{
			algo->stepY = 1;
			algo->sideDistY = (algo->mapY + 1.0 - algo->posY)
				* algo->deltaDistY;
		}
		while (algo->hit == 0)
		{
			if (algo->sideDistX < algo->sideDistY)
			{
				algo->sideDistX += algo->deltaDistX;
				algo->mapX += algo->stepX;
				algo->side = 0;
			}
			else
			{
				algo->sideDistY += algo->deltaDistY;
				algo->mapY += algo->stepY;
				algo->side = 1;
			}
			if (worldMap[algo->mapX][algo->mapY] > 0)
				algo->hit = 1;
		}
		if (algo->side == 0)
			algo->perpWallDist = (algo->mapX - algo->posX
				+ (1 - algo->stepX) / 2) / algo->rayDirX;
		else
			algo->perpWallDist = (algo->mapY - algo->posY
				+ (1 - algo->stepY) / 2) / algo->rayDirY;
		algo->lineHeight = (int)(data->height / algo->perpWallDist);
		algo->drawStart = -(algo->lineHeight) / 2 + data->height / 2;
		if (algo->drawStart < 0)
			algo->drawStart = 0;
		algo->drawEnd = algo->lineHeight / 2 + data->height / 2;
		if (algo->drawEnd >= data->height)
			algo->drawEnd = data->height - 1;
		data->color = 0xf55d42;
		if (algo->side == 1)
			data->color = (data->color / 2);
		ft_painting(data, algo);
		algo->x++;
	}
//	if (!(algo = (t_algo *)malloc(sizeof(t_algo))))
//		return (0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_key_hook(data->win_ptr, ft_keyparsing, algo);
	ft_move(algo, data);
//	init_struct(algo, data);
	ft_ray(algo, data);
	mlx_loop_hook(data->mlx_ptr, ft_move, algo);
	mlx_loop(data->mlx_ptr);
}
