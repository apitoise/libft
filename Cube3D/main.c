/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:30:32 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/21 17:56:21 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		main(void)
{
	t_twostruct	*twostruct;

	init_first(twostruct->algo);
	init_struct(twostruct->algo, twostruct->data);
	ft_raycasting(twostruct->algo, twostruct->data);
	mlx_loop_hook(twostruct->data->mlx_ptr, ft_move, twostruct);
	mlx_loop(twostruct->data->mlx_ptr);
	return (0);
}
