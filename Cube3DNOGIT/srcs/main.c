/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:15:24 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/06 16:50:07 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/Libft/libft.h"

int		main(int ac, char **av)
{
	t_algo	t;

	if (ac != 2)
	{
		if (ac < 2)
			ft_putstr_fd("No map in argument.\n");
		else
			ft_putstr_fd("Too many arguments.\n");
		return (0);
	}
	if (!(t = (t_algo *)malloc(sizeof(t_algo))))
		return (0);
	if (!(parser(t, av)))
		return (0);
	mlx_win_init(t);
	mlx_hook(t->win, 17, 0L, ft_close, t);
	mlx_hook(t->win, 2, (1L << 0), key_press, t);
	mlx_hook(t->win, 3, (1L << 1), key_release, t);
	t->help = 1;
	algo_init(t);
	ray_casting(t);
	mlx_loop_hook(t->mlx, move, t);
	mlx_loop(t->mlx);
}
