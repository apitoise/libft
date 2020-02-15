/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:49:34 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/12 15:55:47 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

int		ft_close(t_allstruct *all)
{
	ft_free(all);
	mlx_destroy_window(all->data.mlx_ptr, all->data.win_ptr);
	exit(1);
	return (0);
}

int		ft_keyrelease(int key, t_allstruct *all)
{
	if (key == 13)
		all->algo.move_up = 0;
	if (key == 0)
		all->algo.move_left = 0;
	if (key == 123)
		all->algo.rot_left = 0;
	if (key == 1)
		all->algo.move_down = 0;
	if (key == 2)
		all->algo.move_right = 0;
	if (key == 124)
		all->algo.rot_right = 0;
	return (0);
}

int		ft_keyparsing(int key, t_allstruct *all)
{
	if (key == 13)
		all->algo.move_up = 1;
	if (key == 0)
		all->algo.move_left = 1;
	if (key == 123)
		all->algo.rot_left = 1;
	if (key == 1)
		all->algo.move_down = 1;
	if (key == 2)
		all->algo.move_right = 1;
	if (key == 124)
		all->algo.rot_right = 1;
	if (key == 53)
		return (ft_close(all));
	ft_move(all);
	return (0);
}
