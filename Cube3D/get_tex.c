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

#include "cube3d.h"

void	get_tex(t_allstruct *all)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		all->tex[i].teximg = mlx_xpm_file_to_image(all->data.mlx_ptr,
			all->tex[i].name, &all->tex[i].w, &all->tex[i].h);
		all->tex[i].data = (int *)mlx_get_data_addr(all->tex[i].teximg,
			&all->tex[i].bpp, &all->tex[i].size_line, &all->tex[i].endian);
		i++;
	}
}