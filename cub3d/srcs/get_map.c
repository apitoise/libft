/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:36:31 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/15 14:00:02 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

static int		get_value(char c)
{
	if (c == ' ')
		return (9);
	else if (c == 'N')
		return (8);
	else if (c == 'W')
		return (7);
	else if (c == 'S')
		return (6);
	else if (c == 'E')
		return (5);
	else
		return (ft_atoi(&c));
}

static int		ft_isok(char c, t_allstruct *all)
{
	if (c == ' ' || c == 'N' || c == 'W' || c == 'S' || c == 'E'
		|| c == '0' || c == '1' || c == '2')
	{
		if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
			all->map.spawn++;
		if (c == '2')
			all->map.nb_sprt++;
		return (1);
	}
	else
		return (0);
}

static int		create_map_bis(int i, int j, t_allstruct *all)
{
	get_spawn(all->map.map[i][j], i, j, all);
	return (j + 1);
}

int				create_map(t_allstruct *all)
{
	int		i;
	int		j;

	i = 0;
	if (!(all->map.map = malloc(sizeof(int *) * all->map.height)))
		return (-1);
	while (i < all->map.height)
	{
		if (!(all->map.map[i] = malloc(sizeof(int) * all->map.width)))
			return (-1);
		j = 0;
		while (j < all->map.width)
		{
			if (ft_isok(all->map.charmap[all->map.d], all))
			{
				all->map.map[i][j] = get_value(all->map.charmap[all->map.d]);
				j = (create_map_bis(i, j, all));
			}
			else
				return (0);
			all->map.d++;
		}
		i++;
	}
	return (1);
}

void			get_map(char *line, t_allstruct *all)
{
	char	*tmp;

	all->map.height++;
	if (all->map.first == 0)
	{
		all->map.charmap = NULL;
		all->map.width = ft_strlen(line);
		all->map.first = 1;
		all->map.charmap = ft_gnlstrjoin(all->map.charmap, line);
	}
	else
	{
		if (ft_strlen(line) != (size_t)all->map.width)
			all->map.lenerror = 1;
		tmp = ft_strjoin(all->map.charmap, line);
		free(all->map.charmap);
		all->map.charmap = tmp;
	}
}
