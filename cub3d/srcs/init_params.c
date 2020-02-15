/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:53:13 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/12 15:57:51 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cube3d.h"

static int	init_crd_bis(char c, char *str, t_allstruct *all)
{
	int		res;

	res = -1;
	if (c == 'N' && str[1] == 'O')
	{
		all->map.argno++;
		res = 0;
	}
	else if (c == 'S' && str[1] == 'O')
	{
		all->map.argso++;
		res = 1;
	}
	else if (c == 'W' && str[1] == 'E')
	{
		all->map.argw++;
		res = 2;
	}
	else if (c == 'E' && str[1] == 'A')
	{
		all->map.arge++;
		res = 3;
	}
	return (res);
}

int			init_crd(char c, char *str, t_allstruct *all)
{
	int		res;

	res = init_crd_bis(c, str, all);
	if (all->map.argno > 1 || all->map.argso > 1 || all->map.arge > 1
		|| all->map.argw > 1)
		all->map.error = 6;
	return (res);
}

void		get_xpm_name(char *str, int crd, t_allstruct *all)
{
	int		j;
	int		i;

	j = 2;
	i = 0;
	while (str[j] == ' ')
		j++;
	str = str + j;
	if (str == NULL)
		return ;
	while ((str[i] != ' ' || str[i] != '\n') && str[i])
		i++;
	if (crd < 4)
		all->tex[crd].name = ft_substr(str, 0, i);
	else if (crd == 4)
		all->map.sprtname = ft_substr(str, 0, i);
}

void		init_res(char *str, t_allstruct *all)
{
	int		i;

	i = 2;
	all->map.argr++;
	if (all->map.argr > 1)
		all->map.error = 6;
	all->data.width = ft_atoi(&str[i]);
	all->data.width = all->data.width > 2560 ? 2560 : all->data.width;
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] == ' ')
		i++;
	all->data.height = ft_atoi(&str[i]);
	if (all->data.height <= 0 || all->data.width <= 0)
		all->map.error = 8;
	all->data.height = all->data.height > 1440 ? 1440 : all->data.height;
}

void		init_tex(char c, char *str, t_allstruct *all)
{
	int		crd;

	crd = init_crd(c, str, all);
	if (crd >= 0 && crd <= 3)
		get_xpm_name(str, crd, all);
}
