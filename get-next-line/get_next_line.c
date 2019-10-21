/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:11:03 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/21 18:41:27 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // a supprimer

size_t				ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int			ft_createline(char	**res, char **line, size_t len, int fd)
{
	char	*tmp;

	if (res[fd][len] == '\n')
	{
		printf("%ld\n", len);
		if(!(*line = ft_substr(res[fd], 0, len)))
			return (-1);
		if(!(tmp = ft_strdup(res[fd] + len + 1)))
			return (-1);
		free(res[fd]);
		res[fd] = tmp;
	}
	else
	{
		if (!(*line = ft_strdup(res[fd])))
			return (-1);
		free(res[fd]);
	}
	return (1);
}

static int		ft_read(int fd, char **res, size_t ret)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;

	while (ret == read(fd, &buff, BUFFER_SIZE) > 0)
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(res[fd], buff)))
			return (-1);
		free(res[fd]);
		res[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ret);
}	

int				get_next_line(int fd, char **line)
{
	static char 	*res[MAX_FD];
	size_t			len;
	static int 		ret;

	ret = 1;
	len = 0;
	if (fd < 0 || line == NULL || fd > MAX_FD || BUFFER_SIZE < 1)
		return (-1);
	if (!res[fd])
		if (!(res[fd] = (char *)malloc(1)))
			return (-1);
	while (res[fd][len] != '\n' && res[fd][len] != '\0')
		len++;
	printf("%ld\n", len);
	if (res[fd][len] == '\n')
		return (ft_createline(res, line, len, fd));
	else
	{
		ret = ft_read(fd, res, ret);
		if (ret < 0)
			return (-1);
		else if (ret == 0 && res[fd][0] == '\0')
			return (0);
	}
	return (ft_createline(res, line, len, fd));
}	
