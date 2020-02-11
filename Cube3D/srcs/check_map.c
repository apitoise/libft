/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:32:46 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/04 16:35:02 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

int		check_map(t_allstruct *all)
{
	int		i;

	i = 0;
	while (all->map.map[0][i] == 1 && i < all->map.width - 1)
		i++;
	if (all->map.map[0][i] != 1)
		return (1);
	i = 0;
	while (all->map.map[i][0] == 1 &&
		all->map.map[i][all->map.width - 1] == 1 && i < all->map.height - 1)
		i++;
	if (all->map.map[i][0] != 1 || all->map.map[i][all->map.width - 1] != 1)
		return (1);
	i = 0;
	if (all->map.map[all->map.height - 1][i] == 1 && all->map.width - 1)
		i++;
	if (all->map.map[all->map.height - 1][i] != 1)
		return (1);
	if (all->map.spawn > 1)
		return (2);
	if (all->map.spawn < 1)
		return (3);
	return (0);
}