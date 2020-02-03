/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:20:12 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/31 13:20:14 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		get_tex(t_allstruct *all)
{
	int 	w;
	int 	h;
	int 	i;

	i = 0;
	while (i < 3)
	{
		all->tex[i].teximg = mlx_xpm_file_to_image(all->data.mlx_ptr,
			all->tex[i].name, &w, &h);
		all->tex[i].data = mlx_get_data_addr(all->tex[i].teximg,
			&all->tex[i].bpp, &all->tex[i].size_line, &all->tex[i].endian);
		i++;
	}
}