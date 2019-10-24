/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:52:53 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/23 18:21:58 by apitoise         ###   ########.fr       */
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
		*file = tmp;
		free(tmp);
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

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(ret = ft_read(fd, &file)))
		return (-1);
	pos = 0;
	if (!file)
		if (!(file = malloc(1)))
			return (-1);
	while (file[pos] && file[pos] != '\n')
		pos++;
	if (!(*line = ft_substr(file, 0, pos)))
		return (-1);
	if (file[pos] || ret != 0)
	{
		file += pos + 1;
		return (1);
	}
	else
		return (0);
}
