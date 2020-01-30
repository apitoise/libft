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

	ret = 1;
	fd = open(cub, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(cub);
		ft_putstr_fd(": No such file\n");
		return (-1);
	}
	while (ret > 0)
	{
		if ((ret = get_next_line(fd, &line)) == -1)
			return (-1);
		if (line[0] == 'R')
			init_res(line, all);
		printf("%s\n", all->tex[0].name);
		if (line[0] == 'N' || line[0] == 'S'
			|| line[0] == 'W' || line[0] == 'E')
			init_tex(line[0], line, all);
/*		if (line[0] == 'S' && line[1] == ' ')
			init_sprite(line, all);
		if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
			init_colors(line[0], line, all);
		if (line[0] == '1')
			get_map(line, all);*/
	}
	return (0);
}

static int	check_cub(char *cub, t_allstruct *all)
{
	int		last;

	last = ft_strlen(cub) - 1;
	if (!(ft_strncmp(&cub[last - 3], ".cub", 4)))
	{
		read_cub(cub, all);
		return (1);
	}
	else
		return(0);
}

int			check_arguments(int	ac, char **av, t_allstruct *all)
{
	if (ac > 3)
	{
		ft_putstr_fd("Too many arguments.\n");
		return (0);
	}
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "-save", 6) != 0)
		{
			ft_putstr_fd("Second argument is not accepted.\n");
			return (0);
		}
	}
	if (ac < 2)
	{
		ft_putstr_fd("No .cub\n");
		return (0);
	}
	if (!(check_cub(av[1], all)))
		ft_putstr_fd("This file is not a .cub");
	return (1);
}