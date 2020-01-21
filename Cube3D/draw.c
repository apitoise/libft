/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:35:47 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/21 17:01:27 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	put_pxl_to_img(t_algo *algo, int x, int y, t_data *data)
{
	if (x < WINX && y < WINY)
		ft_memcpy(data->img_ptr + 4 * WINX * y + x *4,
			&data->color, sizeof(int));
}

void	draw_wall(t_algo *algo, t_data *data)
{
	while (++algo->drawStart <= algo->drawEnd)
		put_pxl_to_img(algo, algo->x, algo->drawStart, data);
}
