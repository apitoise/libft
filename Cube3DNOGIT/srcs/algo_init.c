/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:42:27 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/06 16:47:40 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft/libft.h"
#include "../includes/cube3d.h"

void	algo_init(t_algo *t)
{
	t->x_pos = 3;
	t->y_pos = 3;
	t->x_dir = -1;
	t->y_dir = 0;
	t->x_plane = 0.66;
	t->ms = 0.05;
	t->rs = 0.05;
	t->move_up = 0;
	t->move_down = 0;
	t->move_left = 0;
	t->move_right = 0;
	t->x_test = 0;
	t->y_test = 0;
}
