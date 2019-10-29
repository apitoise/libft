/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:52:53 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/29 18:01:47 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read(int fd, char **file)
{
	char	*tmp;
	char	buff[BUFFER_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buff, BUFFER_SIZE)))
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(*file, buff)))
			return (-1);
		free(*file);
		*file = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static char		*file;
	int				pos;
	int				ret;
	char			*tmp;

	pos = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if ((ret = ft_read(fd, &file) < 0))
		return (-1);
	if (!(file))
		file = malloc(1);
	printf("ret = %d\n", ret);	
	if (file[pos])
	{
		while (file[pos] && file[pos] != '\n')
			pos++;
		if (!(*line = ft_substr(file, 0, pos)))
			return (-1);
		tmp = ft_strdup(file + pos + 1);
		free(file);
		file = tmp;
		return (1);
	}
	*line = ft_strdup("");
	return (0);
}
