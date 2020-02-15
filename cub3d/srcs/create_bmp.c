/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 21:14:51 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/15 15:45:14 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

static void		write_header(int fd, t_allstruct *all)
{
	int		size_line;

	write(fd, "BM", 2);
	size_line = all->data.width * 3;
	size_line += size_line % 4 ? 4 - size_line % 4 : size_line;
	size_line += 4 - size_line % 4;
	write_int(fd, 54 + size_line * all->data.height);
	write_int(fd, 0);
	write_int(fd, 54);
}

static void		write_info(int fd, t_allstruct *all)
{
	write_int(fd, 40);
	write_int(fd, all->data.width);
	write_int(fd, all->data.height);
	write_half_int(fd, 1);
	write_half_int(fd, 24);
	write_int(fd, 0);
	write_int(fd, 0);
	write_int(fd, 6400);
	write_int(fd, 6400);
	write_int(fd, 0);
	write_int(fd, 0);
}

static void		write_pixels(int fd, t_allstruct *all)
{
	unsigned int	color;
	int				i;
	int				j;
	int				rem;

	rem = all->data.width * 3 % 4;
	i = all->data.height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < all->data.width)
		{
			color = *(all->data.data_ptr + (all->data.width * i) + j);
			write_color(fd, color);
			j++;
			if (rem)
				write_empty(fd, 4 - rem);
		}
		i--;
	}
}

int				create_bmp(char *file, t_allstruct *all)
{
	int		fd;

	if (!(fd = open(file, O_WRONLY | O_CREAT, 0666)))
		return (0);
	write_header(fd, all);
	write_info(fd, all);
	write_pixels(fd, all);
	close(fd);
	return (0);
}
