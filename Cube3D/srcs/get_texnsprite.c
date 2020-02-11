/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:20:12 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/04 16:43:25 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

void	get_sprites_pos(t_allstruct *all)
{
	int 	i;
	int 	j;
	int 	nb;

	i = 0;
	nb = 0;
	while (i < all->map.height)
	{
		j = 0;
		while (j < all->map.width)
		{
			if (all->map.map[i][j] == 2)
			{
				all->sprt[nb].posX = i;
				all->sprt[nb].posY = j;
				nb++;
			}
			j++;
		}
		i++;
	}
}

void	get_sprite(t_allstruct *all)
{
	int 	i;

	if (!(all->sprt = malloc(sizeof(t_sprt)
		* all->map.nbSprites)))
		return ;
	get_sprites_pos(all);
	i = 0;
	while (i < all->map.nbSprites)
	{
		if (!(all->sprt[i].sprtimg = mlx_xpm_file_to_image(all->data.mlx_ptr,
			all->map.sprtname, &all->sprt[i].w, &all->sprt[i].h)))
		{
			all->sprtError = 1;
			return ;
		}
		all->sprt[i].data = (int *)mlx_get_data_addr(all->sprt[i].sprtimg,
			&all->sprt[i].bpp, &all->sprt[i].size_line, &all->sprt[i].endian);
		all->sprt[i].distance = ((all->algo.posX - all->sprt[i].posX)
			* (all->algo.posX - all->sprt[i].posX) +
			(all->algo.posY - all->sprt[i].posY) *
			(all->algo.posY - all->sprt[i].posY));
		i++;
	}
}

void	init_sprite(char *str, t_allstruct *all)
{
	all->map.sprtname = get_xpm_name(str);
}

void	get_tex(t_allstruct *all)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (!(all->tex[i].teximg = mlx_xpm_file_to_image(all->data.mlx_ptr,
			all->tex[i].name, &all->tex[i].w, &all->tex[i].h)))
		{
			all->texError = 1;
			return ;
		}
		all->tex[i].data = (int *)mlx_get_data_addr(all->tex[i].teximg,
			&all->tex[i].bpp, &all->tex[i].size_line, &all->tex[i].endian);
		i++;
	}
}