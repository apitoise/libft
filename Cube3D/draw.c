/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:35:47 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/22 14:45:00 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_painting(t_algo *algo, t_data *data)
{
	int		y;

	y = algo->drawStart;
	while (y < algo->drawEnd)
	{
		*(data->data_ptr + (WINX * y) + algo->x) = data->color;
		y++;
	}
}

void	draw_wall(t_algo *algo, t_data *data)
{
//	while (++algo->drawStart <= algo->drawEnd)
		ft_painting(algo, data);
}
