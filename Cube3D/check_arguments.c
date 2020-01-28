/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:24:16 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/28 15:24:21 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube3d.h"

int		check_arguments(int	ac, char **av)
{
	if (ac > 3)
	{
		ft_putstr_fd("Too many arguments.\n");
		return (0);
	}
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "-save", 6) != 0)
		{
			ft_putstr_fd("Second argument is not accepted.\n");
			return (0);
		}
	}
	return (1);
}