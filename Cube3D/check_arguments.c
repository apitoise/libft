/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:24:16 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/28 15:24:21 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube3d.h"

static int	read_cub(char *cub, t_allstruct *all)
{
	int		fd;
	int		ret;
	char 	*line;
	int 	error;

	ret = 1;
	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (0);
	while (ret > 0)
	{
		if ((ret = get_next_line(fd, &line)) == -1)
			return (-1);
		if (line[0] == 'R')
			init_res(line, all);
		if (line[0] == 'N' || (line[0] == 'S' && line[1] == 'O')
			|| line[0] == 'W' || line[0] == 'E')
			init_tex(line[0], line, all);
//		if (line[0] == 'S' && line[1] == ' ')
//			init_sprite(line, all);
		if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
			init_colors(line[0], line, all);
		if (ft_isdigit(line[0]))
			get_map(line, all);
	}
	if (all->map.lenerror == 0)
	{
		if (!(create_map(all)))
		{
			all->map.lenerror = 5;
			return (ft_error("Invalid character in map."));
		}
	}
	else
		return (ft_error("The map is not rectangular."));
	error = check_map(all);
	if (error == 1)
		ft_error("Map is not closed.");
	if (error == 2)
		ft_error("Too much spawn.");
	if (error == 3)
		ft_error("There is no spawn.");
	int i = 0;
	while (i < all->map.height)
	{
		int j = 0;
		while (j < all->map.width)
		{
			printf("%d", all->map.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (1);
}

static int	check_cub(char *cub, t_allstruct *all)
{
	int		last;
	int 	err;

	last = ft_strlen(cub) - 1;
	if (!(ft_strncmp(&cub[last - 3], ".cub", 4)))
	{
		err = read_cub(cub, all);
		if (err == 0)
		{
			if (all->map.lenerror == 0)
				return (ft_error("Invalid .cub."));
			else
				return (0);
		}
		else if (err == -1)
			return (ft_error(".cub is not a file."));
		return (1);
	}
	else
		return(ft_error("Second argument is not a .cub."));
}

int			check_arguments(int	ac, char **av, t_allstruct *all)
{
	if (ac > 3)
		return (ft_error("Too many arguments."));
	if (ac == 3)
		if (ft_strncmp(av[2], "-save", 6) != 0)
			return (ft_error("Second argument is not accepted."));
	if (ac < 2)
		return (ft_error("No .cub"));
	if (!(check_cub(av[1], all)))
		return (0);
	return (1);
}