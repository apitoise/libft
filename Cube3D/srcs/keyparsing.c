/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:49:34 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/04 17:20:58 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

int		ft_close(void)
{
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
		exit(1);
	ft_move(all);
	return (0);
}