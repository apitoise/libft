/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:21:49 by apitoise          #+#    #+#             */
/*   Updated: 2020/07/16 16:38:38 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_one.h"

void	ft_eat(t_philo *philo)
{
//	pthread_mutex_lock(&philo->eat_m);
	philo->is_eating = 1;
	display_message(philo->id, "is eating.", philo);
	usleep(philo->data.eat * 1000);
	philo->is_eating = 0;
//	pthread_mutex_unlock(&philo->eat_m);
	if (get_time() > philo->limit)
		ft_dead(philo);
}
