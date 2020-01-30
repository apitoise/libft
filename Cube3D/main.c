/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:30:32 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/23 15:15:37 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "Libft/libft.h"

int		main(int ac, char **av)
{
	t_allstruct	*all;

	if (!(all = (t_allstruct *)malloc(sizeof(t_allstruct))))
		return (0);
	if (!(check_arguments(ac, av, all)))
		return (0);
	init_struct(all);
	mlx_hook(all->data.win_ptr, 17, 0L, ft_close, all);
	mlx_hook(all->data.win_ptr, 2, (1L << 0), ft_keyparsing, all);
	mlx_hook(all->data.win_ptr, 3, (1L << 1), ft_keyrelease, all);
	ft_raycasting(all);
	mlx_loop_hook(all->data.mlx_ptr, ft_move, all);
	mlx_loop(all->data.mlx_ptr);
}
