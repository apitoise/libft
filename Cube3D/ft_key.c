/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:49:34 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/22 15:07:25 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_close(int key, t_twostruct *ts)
{
	exit(1);
	return (0);
}

int		ft_keyrelease(int key, t_twostruct *ts)
{
	if (key == 13)
		ts->algo.move_up = 0;
	if (key == 0)
		ts->algo.move_left = 0;
	if (key == 123)
		ts->algo.rot_left = 0;
	if (key == 1)
		ts->algo.move_down = 0;
	if (key == 2)
		ts->algo.move_right = 0;
	if (key == 124)
		ts->algo.rot_right = 0;
	return (0);
}

int		ft_keyparsing(int key, t_twostruct *ts)
{

	if (key == 13)
		ts->algo.move_up = 1;
	if (key == 0)
		ts->algo.move_left = 1;
	if (key == 123)
		ts->algo.rot_left = 1;
	if (key == 1)
		ts->algo.move_down = 1;
	if (key == 2)
		ts->algo.move_right = 1;
	if (key == 124)
		ts->algo.rot_right = 1;
	if (key == 53)
		exit(1);
	ft_move(ts);
	return (0);
}