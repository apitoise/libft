/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:20:12 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/12 15:55:10 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

void	get_sprites_pos(t_allstruct *all)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	nb = 0;
	while (i < all->map.height)
	{
		j = 0;
		while (j < all->map.width)
		{
			if (all->map.map[i][j] == 2)
			{
				all->sprt[nb].posx = i;
				all->sprt[nb].posy = j;
				nb++;
			}
			j++;
		}
		i++;
	}
}

void	get_sprite(t_allstruct *all)
{
	int		i;

	if (!(all->sprt = malloc(sizeof(t_sprt)
		* all->map.nb_sprt)))
		return ;
	get_sprites_pos(all);
	i = 0;
	while (i < all->map.nb_sprt)
	{
		if (!(all->sprt[i].sprtimg = mlx_xpm_file_to_image(all->data.mlx_ptr,
			all->map.sprtname, &all->sprt[i].w, &all->sprt[i].h)))
		{
			all->sprterror = 1;
			return ;
		}
		all->sprt[i].data = (int *)mlx_get_data_addr(all->sprt[i].sprtimg,
			&all->sprt[i].bpp, &all->sprt[i].size_line, &all->sprt[i].endian);
		all->sprt[i].distance = ((all->algo.posx - all->sprt[i].posx)
			* (all->algo.posx - all->sprt[i].posx) +
			(all->algo.posy - all->sprt[i].posy) *
			(all->algo.posy - all->sprt[i].posy));
		i++;
	}
}

void	init_sprite(char *str, t_allstruct *all)
{
	all->map.args++;
	if (all->map.args > 1)
		all->map.error = 6;
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
			all->texerror = 1;
			return ;
		}
		all->tex[i].data = (int *)mlx_get_data_addr(all->tex[i].teximg,
			&all->tex[i].bpp, &all->tex[i].size_line, &all->tex[i].endian);
		i++;
	}
}
