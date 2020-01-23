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

void	ft_raycasting(t_algo *algo, t_data *data)
{
	algo->x = -1;
	init_datastruct(data);
	while (++algo->x < WINX)
	{
		init_loop_algostruct(algo);
		algo->lineHeight = (int)(WINY / algo->perpWallDist);
		algo->drawStart = -algo->lineHeight / 2 + WINY / 2;
		if (algo->drawStart < 0)
			algo->drawStart = 0;
		algo->drawEnd = algo->lineHeight / 2 + WINY / 2;
		if (algo->drawEnd >= WINY)
			algo->drawEnd = WINY - 1;
		ft_painting(algo, data);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
}
