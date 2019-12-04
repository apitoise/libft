/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:49:34 by apitoise          #+#    #+#             */
/*   Updated: 2019/12/04 17:30:15 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_keyparsing(int key, void *param)
{
	t_data	data;

	if (key == 13)
		w_key(param);
//	if (key == 0)
//		a_key();
//	if (key == 1)
//		s_key();
//	if (key == 2)
//		d_key();
//	if (key == 126)
//		up_key();
//	if (key == 123)
//		left_key();
//	if (key == 125)
//		down_key();
//	if (key == 124)
//		right_key();
//	if (key == 53)
//		echap_key();
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
