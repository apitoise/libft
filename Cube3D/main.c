/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:30:32 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/22 15:00:25 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		main(void)
{
	t_twostruct	*ts;
	t_data		data;
	t_algo		algo;

	if (!(ts = (t_twostruct *)malloc(sizeof(t_twostruct))))
		return (0);
//	init_first(ts->algo);
	printf("move_up = %d\n", algo.move_up);
	init_struct(&algo, &data);
	ft_raycasting(&algo, &data);
	ts->algo = algo;
	ts->data = data;
	mlx_key_hook(data.win_ptr, ft_keyparsing, ts);
	mlx_loop_hook(data.mlx_ptr, ft_move, ts);
	mlx_loop(data.mlx_ptr);
}
