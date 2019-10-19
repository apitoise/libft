/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:11:03 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/19 16:58:20 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_createline(char	**res, char **line, size_t len)
{
	char	*tmp;

	if (!(line = malloc((len + 1) * sizeof(char))))
		return (-1);
	if (len > 0)
	{
		if(!(*line = ft_substr(*res, 0, len)));
			return (-1);
		if(!(tmp = ft_strdup(*res + len + 1)))
			return (-1);
		free(*res);
		*res = tmp;
		return (1);
	}
	return (0);
}

int		ft_read(char **res, char **line, int len)
{
	while (*line = read(*res, *line, len))
	return(0);
}	

int		get_next_line(int fd, char **line)
{
	static char *res[fd];
	size_t			len;

	len = 0;
	if (!fd || !line)
		return (-1);	
	if (!(res[fd] = malloc(1)))
		return (-1);
	while (fd != 0)
	{
		while (*res[fd] != '\n' ||*res[fd] != '\0')
		{
			len++;
			fd++;
		}
		ft_createline(res, line, len);
	}
	ft_read(res, line, len);
}	
