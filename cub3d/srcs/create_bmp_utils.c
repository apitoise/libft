/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 22:18:35 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/15 13:32:54 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

void	write_half_int(int fd, int nb)
{
	char	byt;

	byt = nb & 0xff;
	write(fd, &byt, 1);
	byt = (nb >> 8) & 0xff;
	write(fd, &byt, 1);
}

void	write_int(int fd, int nb)
{
	write_half_int(fd, nb);
	write_half_int(fd, nb >> 16);
}

void	write_color(int fd, int color)
{
	char	byt;

	write_half_int(fd, color);
	byt = color >> 16 & 0xff;
	write(fd, &byt, 1);
}

void	write_empty(int fd, int nb)
{
	while (nb)
	{
		write(fd, "\0", 1);
		nb--;
	}
}
