/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:43:20 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/09 14:23:19 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_moveup(t_algo *algo)
{
	if (worldMap[(int)(algo->posX + algo->dirX * algo->ms)]
			[(int)(algo->posY)] == 0)
		algo->posX += algo->dirX * algo->ms;
	if (worldMap[(int)(algo->posX)]
			[(int)(algo->posY + algo->dirY * algo->ms)] == 0)
		algo->posY += algo->dirY * algo->ms;
}

int		ft_move(t_algo *algo)
{
	if (algo->move_up == 1)
		ft_moveup(algo);
//	if (algo->move_down == 1)
//		ft_movedown(algo);
//	if (algo->move_left == 1)
//		ft_moveleft(algo);
//	if (algo->moveright == 1)
//		ft_moveright(algo);
//	ft_ray(algo);
	return (0);
}
