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

int 	init_crd(char c, char *str)
{
	int 	res;

	res = -1;
	if (c == 'N' && str[1] == 'O')
		res = 0;
	else if (c == 'S' && str[1] == 'O')
		res = 1;
	else if (c == 'W' && str[1] == 'E')
		res = 2;
	else if (c == 'E' && str[1] == 'A')
		res = 3;
	return (res);
}

char	*get_xpm_name(char *str, t_allstruct *all)
{
	char	*res;
	int 	j;
	int 	i;

	j = 2;
	i = 0;
	while (str[j] == ' ')
		j++;
	str = str + j;
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
	all->data.width = all->data.width > 2560 ? 2560 : all->data.width;
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] == ' ')
		i++;
	all->data.height = ft_atoi(&str[i]);
	all->data.height = all->data.height > 1440 ? 1440 : all->data.height;
}


void	init_tex(char c, char *str, t_allstruct *all)
{
	int 	crd;

	crd = init_crd(c, str);
	if (crd == 0)
		all->tex[crd].name = get_xpm_name(str, all);
	else if (crd == 1)
		all->tex[crd].name = get_xpm_name(str, all);
	else if (crd == 2)
		all->tex[crd].name = get_xpm_name(str, all);
	else if (crd == 3)
		all->tex[crd].name = get_xpm_name(str, all);
}