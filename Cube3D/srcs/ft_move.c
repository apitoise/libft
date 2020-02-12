/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:43:20 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/12 15:52:35 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

static void		ft_moveupndown(t_allstruct *all)
{
	if (all->algo.move_up == 1)
	{
		if (all->map.map[(int)(all->algo.posx + all->algo.dirx * all->algo.ms)]
				[(int)(all->algo.posy)] != 1)
			all->algo.posx += all->algo.dirx * all->algo.ms;
		if (all->map.map[(int)(all->algo.posx)]
				[(int)(all->algo.posy + all->algo.diry * all->algo.ms)] != 1)
			all->algo.posy += all->algo.diry * all->algo.ms;
	}
	else if (all->algo.move_down == 1)
	{
		if (all->map.map[(int)(all->algo.posx - all->algo.dirx * all->algo.ms)]
				[(int)(all->algo.posy)] != 1)
			all->algo.posx -= all->algo.dirx * all->algo.ms;
		if (all->map.map[(int)(all->algo.posx)]
				[(int)(all->algo.posy - all->algo.diry * all->algo.ms)] != 1)
			all->algo.posy -= all->algo.diry * all->algo.ms;
	}
}

static void		ft_moveside(t_allstruct *all)
{
	if (all->algo.move_left == 1)
	{
		if (all->map.map[(int)(all->algo.posx - all->algo.planex
			* all->algo.ms)][(int)(all->algo.posy)] != 1)
			all->algo.posx -= all->algo.planex * all->algo.ms;
		if (all->map.map[(int)(all->algo.posx)]
				[(int)(all->algo.posy - all->algo.planey * all->algo.ms)] != 1)
			all->algo.posy -= all->algo.planey * all->algo.ms;
	}
	else if (all->algo.move_right == 1)
	{
		if (all->map.map[(int)(all->algo.posx + all->algo.planex
			* all->algo.ms)][(int)(all->algo.posy)] != 1)
			all->algo.posx += all->algo.planex * all->algo.ms;
		if (all->map.map[(int)(all->algo.posx)]
				[(int)(all->algo.posy + all->algo.planey * all->algo.ms)] != 1)
			all->algo.posy += all->algo.planey * all->algo.ms;
	}
}

static void		ft_rot_left(t_allstruct *all)
{
	all->algo.olddirx = all->algo.dirx;
	all->algo.dirx = all->algo.dirx * cos(all->algo.rs)
		- all->algo.diry * sin(all->algo.rs);
	all->algo.diry = all->algo.olddirx * sin(all->algo.rs)
		+ all->algo.diry * cos(all->algo.rs);
	all->algo.oldplanex = all->algo.planex;
	all->algo.planex = all->algo.planex * cos(all->algo.rs)
		- all->algo.planey * sin(all->algo.rs);
	all->algo.planey = all->algo.oldplanex * sin(all->algo.rs)
		+ all->algo.planey * cos(all->algo.rs);
}

static void		ft_rotation(t_allstruct *all)
{
	if (all->algo.rot_right == 1)
	{
		all->algo.olddirx = all->algo.dirx;
		all->algo.dirx = all->algo.dirx * cos(-all->algo.rs)
			- all->algo.diry * sin(-all->algo.rs);
		all->algo.diry = all->algo.olddirx * sin(-all->algo.rs)
			+ all->algo.diry * cos(-all->algo.rs);
		all->algo.oldplanex = all->algo.planex;
		all->algo.planex = all->algo.planex * cos(-all->algo.rs)
			- all->algo.planey * sin(-all->algo.rs);
		all->algo.planey = all->algo.oldplanex * sin(-all->algo.rs)
			+ all->algo.planey * cos(-all->algo.rs);
	}
	else if (all->algo.rot_left == 1)
		ft_rot_left(all);
}

int				ft_move(t_allstruct *all)
{
	if (all->algo.move_up == 1 || all->algo.move_down == 1)
		ft_moveupndown(all);
	if (all->algo.move_right == 1 || all->algo.move_left == 1)
		ft_moveside(all);
	if (all->algo.rot_left == 1 || all->algo.rot_right == 1)
		ft_rotation(all);
	ft_raycasting(all);
	return (0);
}
