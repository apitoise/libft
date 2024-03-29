/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:19:53 by apitoise          #+#    #+#             */
/*   Updated: 2020/07/13 14:19:18 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_one.h"

int		check_value(t_data *data)
{
	if (data->nbphi <= 0 || data->eat <= 0 || data->die <= 0
			|| data->sleep <= 0 || (data->eatmax < 0
				&& data->eatmax != -1))
		return (0);
	else
		return (1);
}

int		get_data(int ac, char **av, t_data *data)
{
	data->nbphi = ft_atoi(av[1]);
	data->eat = ft_atoi(av[3]);
	data->die = ft_atoi(av[2]);
	data->sleep = ft_atoi(av[4]);
	if (ac == 5)
		data->eatmax = -1;
	else
		data->eatmax = ft_atoi(av[5]);
	return (check_value(data));
}
