/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:53:13 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/30 15:53:14 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*get_xpm_name(char *str)
{
	char	*res;
	int 	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while ((str[i] != ' ' || str[i] != '\n') && str[i])
		i++;
	res =  ft_substr(str, 0, i);
	return (res);
}

void	init_res(char *str, t_allstruct *all)
{
	int 	i;

	i = 2;
	all->data.width = ft_atoi(&str[i]);
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] == ' ')
		i++;
	all->data.height = ft_atoi(&str[i]);
}

void	init_tex(char c, char *str, t_allstruct *all)
{
	int 	i;

	if (c == 'N')
	{
		if (str[1] != 'O')
			return ;
		else
		{
			i = 2;
			while (str[i] == ' ')
				i++;
			all->tex[0].name = get_xpm_name(&str[i]);
			printf("%s\n", all->tex[0].name);
		}
	}
}