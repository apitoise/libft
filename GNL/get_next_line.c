/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:52:53 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/22 18:31:23 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int		ft_read(int fd, char **file)
{
	char	*tmp;
	char	buff[BUFFER_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buff, BUFFER_SIZE)))
	{
		buff[ret] = '\0';
		tmp = *file;
		if (!(*file = ft_strjoin(tmp, buff)))
			return (-1);
		free(tmp);
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
	ret = ft_read(fd, &file);
	if (ret < 0)
		return (-1);
	pos = 0;
	while (file[pos] && file[pos] != '\n')
		pos++;
	free(*line);
	if (!(*line = ft_substr(file, 0, pos)))
		return (-1);
	if (file[pos] || pos != ret)
	{
		file += pos + 1;
//		free(*line);
		return (1);
	}
	else
	{
		free(*line);
		line = NULL;
		return (0);
	}
}
