/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:22:29 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/04 16:56:00 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	file_handler(char **file, char **line)
{
	int		i;
	int		ret;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (*file[i])
	{
		while ((*file)[i] != '\n' && (*file)[i])
			i++;
		ret = ((*file)[i] == '\n') ? 1 : 0;
		if (!(*line = ft_gnlsubstr(*file, 0, i)))
			return (-1);
		if (ret == 1)
			if (!(tmp = ft_gnlstrdup(*file + i + 1)))
				return (-1);
		free(*file);
		*file = tmp;
		return (ret);
	}
	free(*file);
	*file = NULL;
	if (!(*line = ft_gnlstrdup("")))
		return (-1);
	return (0);
}

static int	output(char **file, char **line, int ret)
{
	if (ret == -1)
		return (-1);
	if (ret == 0 && *file == NULL)
	{
		*line = ft_gnlstrdup("");
		return (0);
	}
	else
		return (file_handler(file, line));
}

int			get_next_line(int fd, char **line)
{
	static char	*file = NULL;
	int			ret;
	char		*tmp;
	char		buf[10 + 1];

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, 10)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_gnlstrjoin(file, buf);
		free(file);
		file = tmp;
		if (ft_gnlstrchr(file, '\n'))
			break ;
	}
	return (output(&file, line, ret));
}