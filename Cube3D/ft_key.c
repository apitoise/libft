/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:49:34 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/21 12:28:12 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_keyparsing(int key, t_algo *algo)
{
	if (key == 13 || key == 126)
		algo->move_up = 1;
	if (key == 0 || key == 123)
		algo->move_left = 1;
	if (key == 1 || key == 125)
		algo->move_down = 1;
	if (key == 2 || key == 124)
		algo->move_right = 1;
	if (key == 53)
		algo->echapkey = 1;
	return (0);
}

//	mlx_key_hook(win_ptr, ft_key, data_ptr);
/*	readKeys();
    if (keyDown(SDLK_UP))
    {
		if(worldMap[(int)(posX + dirX * moveSpeed)][(int)(posY)] == false) posX += dirX * moveSpeed;
		if(worldMap[(int)posX][(int)(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
    }
    if (keyDown(SDLK_DOWN))
    {
      	if(worldMap[(int)(posX - dirX * moveSpeed)][(int)(posY)] == false) posX -= dirX * moveSpeed;
      	if(worldMap[(int)(posX)][(int)(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    }
    if (keyDown(SDLK_RIGHT))
    {
		double oldDirX = dirX;
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
 	    double oldPlaneX = planeX;
      	planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      	planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    if (keyDown(SDLK_LEFT))
    {
     	double oldDirX = dirX;
     	dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
   		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		double oldPlaneX = planeX;
      	planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      	planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
  }
}*/


/*	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "utils/test.xpm", &width, &height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 225, 225);
	mlx_loop(mlx_ptr);
	return (0);
}*/
