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

int		ft_keyparsing(int key, t_twostruct *ts)
{
	printf("key = %d\n", key);
	if (key == 13 || key == 126)
		ts->algo.move_up = 1;
	if (key == 0 || key == 123)
		ts->algo.move_left = 1;
	if (key == 1 || key == 125)
		ts->algo.move_down = 1;
	if (key == 2 || key == 124)
		ts->algo.move_right = 1;
	if (key == 53)
		ts->algo.echapkey = 1;
	ft_move(ts);
	ts->algo.move_up = 0;
	ts->algo.move_down = 0;
	ts->algo.move_right = 0;
	ts->algo.move_left = 0;
	return (0);
}
