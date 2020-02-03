/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:36:24 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/31 16:36:25 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static char 	*get_char_color(char *str)
{
	int 	end;
	char 	*res;
	char	*tmp;

	end = 0;
	while (ft_isdigit(str[end]))
		end++;
	tmp = ft_substr(str, 0, end);
	res = ft_itoa_base(ft_atoi(tmp), "0123456789abcdef");
	free(tmp);
	return (res);
}

int 			get_color(char *str)
{
	char 	*r;
	char 	*g;
	char 	*b;
	char	*tmp;
	int 	res;

	while (*str == ' ')
		str++;
	r = get_char_color(str);
	while (ft_isdigit(*str))
		str++;
	str++;
	g = get_char_color(str);
	while (ft_isdigit(*str))
		str++;
	str++;
	b = get_char_color(str);
	r = ft_strjoin(r, g);
	tmp = ft_strjoin(r, b);
	free(r);
	free(g);
	free(b);
	res = ft_atoi_base(tmp, 16);
	free(tmp);
	return (res);
}

void 			init_colors(char c, char *str, t_allstruct *all)
{
	char 	*r;
	char 	*g;
	char 	*b;
	char	*tmp;
	char	*res;

	str++;
	if (c == 'F')
		all->data.floor_color = get_color(str);
	if (c == 'C')
		all->data.sky_color = get_color(str);
}