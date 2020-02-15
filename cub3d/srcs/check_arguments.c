/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:24:16 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/15 15:46:20 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

static int	read_error(int error, t_allstruct *all)
{
	if (all->map.error == 6 || all->map.error == 5 || all->map.error == 7
		|| all->map.error == 8 || all->map.error == 9 || all->map.error == 10
		|| all->map.error == 11)
		return (0);
	if (!all->map.argr || !all->map.argno || !all->map.argso || !all->map.argw
		|| !all->map.arge || !all->map.argf || !all->map.argc)
		all->map.error = 7;
	if (all->map.lenerror == 0)
	{
		if (!(create_map(all)))
		{
			all->map.lenerror = 5;
			return (ft_error("Invalid character in map.", all));
		}
	}
	else
		return (ft_error("The map is not rectangular.", all));
	error = check_map(all);
	if (error == 1)
		ft_error("Map is not closed.", all);
	if (error == 2)
		ft_error("Too much spawn.", all);
	if (error == 3)
		ft_error("There is no spawn.", all);
	return (1);
}

static void	read_loop(char *line, t_allstruct *all)
{
	if (all->map.argm)
		all->map.line++;
	if (line[0] == 'R')
		init_res(line, all);
	else if (line[0] == 'N' || (line[0] == 'S' && line[1] == 'O')
		|| line[0] == 'W' || line[0] == 'E')
		init_tex(line[0], line, all);
	else if (line[0] == 'S' && line[1] == ' ')
		init_sprite(line, all);
	else if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
		init_colors(line[0], line, all);
	else if (ft_isdigit(line[0]))
	{
		all->map.argm++;
		if (!all->map.argr || !all->map.argno || !all->map.argso
			|| !all->map.argw || !all->map.arge || !all->map.argf
			|| !all->map.argc)
			all->map.error = 9;
		else
			get_map(line, all);
	}
	else if (line[0] != '\n' && line[0])
		all->map.error = 5;
	free(line);
}

static int	read_cub(char *cub, t_allstruct *all)
{
	int		fd;
	int		ret;
	char	*line;
	int		error;

	ret = 1;
	error = 0;
	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (0);
	while (ret > 0)
	{
		if ((ret = get_next_line(fd, &line)) == -1)
			return (-1);
		read_loop(line, all);
		if (all->map.error == 9)
			break ;
	}
	if (all->map.line > all->map.argm)
		all->map.error = 11;
	if (!all->map.argm)
		all->map.error = 10;
	close(fd);
	return (read_error(error, all));
}

static int	check_cub(char *cub, t_allstruct *all)
{
	int		last;
	int		err;

	last = ft_strlen(cub) - 1;
	if (!(ft_strncmp(&cub[last - 3], ".cub", 4)))
	{
		err = read_cub(cub, all);
		if (err == 0)
			return (find_error(all));
		else if (err == -1)
			return (ft_error(".cub is not a file.", all));
		else if (err == -2)
			return (ft_error("Duplicate arguments.", all));
		return (1);
	}
	else
		return (ft_error("Second argument is not a .cub.", all));
}

int			check_arguments(int ac, char **av, t_allstruct *all)
{
	if (ac > 3)
		return (ft_error("Too many arguments.", all));
	if (ac == 3)
		if (ft_strncmp(av[2], "-save", 6) != 0)
			return (ft_error("Second argument is not accepted.", all));
	if (ac < 2)
		return (ft_error("No .cub", all));
	if (!(check_cub(av[1], all)))
		return (0);
	return (1);
}
