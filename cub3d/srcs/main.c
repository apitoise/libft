/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:30:32 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/12 15:58:47 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"
#include "../Libft/libft.h"

int			ft_free(t_allstruct *all)
{
	free(all->map.charmap);
	return (0);
}

static int	main_bis(int ac, char **av, t_allstruct *all)
{
	init_mapstruct(all);
	if (!(check_arguments(ac, av, all)))
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	t_allstruct	all;

	if (main_bis(ac, av, &all) == 1)
	{
		if (all.map.error == 0)
		{
			init_struct(&all);
			get_tex(&all);
			if (all.texerror == 1)
				return (ft_error("Invalid textures.", &all));
			ft_raycasting(&all);
			if (av[2] && ft_strlen(av[2]) && ft_strncmp(av[2], "-save", 5) == 0)
				return (create_bmp("screen.bmp", &all));
			mlx_hook(all.data.win_ptr, 17, 0L, ft_close, &all);
			mlx_hook(all.data.win_ptr, 2, (1L << 0), ft_keyparsing, &all);
			mlx_hook(all.data.win_ptr, 3, (1L << 1), ft_keyrelease, &all);
			if (all.sprterror == 1)
				return (ft_error("Invalid sprite.", &all));
			mlx_loop_hook(all.data.mlx_ptr, ft_move, &all);
			mlx_loop(all.data.mlx_ptr);
		}
		ft_free(&all);
	}
	return (0);
}
