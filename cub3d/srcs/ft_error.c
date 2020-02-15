/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:09:35 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/15 13:56:10 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

int		ft_error(char *str, t_allstruct *all)
{
	if (all->map.error != 9)
		all->map.error = 1;
	ft_putstr_fd("Error\n");
	ft_putstr_fd(str);
	ft_putchar('\n');
	return (0);
}

int		find_error(t_allstruct *all)
{
	const char	*str = "Map is not at the end of .cub or missing argument.";

	if (all->map.error == 5)
		return (ft_error("Bad argument in .cub.", all));
	if (all->map.error == 6)
		return (ft_error("Duplicate argument in .cub.", all));
	if (all->map.error == 7)
		return (ft_error("Missing argument in .cub.", all));
	if (all->map.error == 8)
		return (ft_error("Bad resolution in .cub.", all));
	if (all->map.error == 9)
		return (ft_error((char *)str, all));
	if (all->map.error == 10)
		return (ft_error((char *)str, all));
	if (all->map.error == 11)
		return (ft_error("Invalid map in .cub.", all));
	if (all->map.lenerror == 0)
		return (ft_error("Invalid .cub.", all));
	else
		return (0);
}
