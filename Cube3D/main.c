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
	t_twostruct	*ts;
	t_data		data;
	t_algo		algo;

	if (!(check_arguments(ac, av)))
		return (0);
	if (!(ts = (t_twostruct *)malloc(sizeof(t_twostruct))))
		return (0);
//	get_next_line_cub(av[1], line)
	init_struct(&algo, &data);
	ts->algo = algo;
	ts->data = data;
	mlx_hook(data.win_ptr, 17, 0L, ft_close, ts);
	mlx_hook(data.win_ptr, 2, (1L << 0), ft_keyparsing, ts);
	mlx_hook(data.win_ptr, 3, (1L << 1), ft_keyrelease, ts);
	ft_raycasting(&ts->algo, &ts->data);
	mlx_loop_hook(data.mlx_ptr, ft_move, ts);
	mlx_loop(data.mlx_ptr);
}
