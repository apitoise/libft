/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_key.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:53:37 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/23 09:52:36 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		w_key(t_algo *algo)
{
	double		moveSpeed;

	moveSpeed = 0.2;
	if (worldMap[(int)(algo->posX + algo->dirX * moveSpeed)]
		[(int)(algo->posY)] == 0)
	{
		printf("OK1\n");
		algo->posX += algo->dirX * moveSpeed;
	}
	printf("%d\n", worldMap[(int)(algo->posX + algo->dirX * moveSpeed)][(int)(algo->posY)]);
	if (worldMap[(int)(algo->posX)]
		[(int)(algo->posY + algo->dirY * moveSpeed)] == 0)
	{
		printf("OK2\n");
		algo->posY += algo->dirY * moveSpeed;
	}
	printf("%d\n", worldMap[(int)(algo->posX)][(int)(algo->posY + algo->dirY * moveSpeed)]);
}
