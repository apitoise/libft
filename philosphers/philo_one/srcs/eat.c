/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:21:49 by apitoise          #+#    #+#             */
/*   Updated: 2020/07/14 16:15:16 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_one.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->is_eating = 1;
	ft_putnbr(get_time() - philo->begin);
	printf("%llu\n", get_time());
	ft_putchar(' ');
	ft_putnbr(philo->id);
	ft_putstr(" is eating.\n");
	usleep(philo->data.eat * 1000);
	printf("%llu\n", get_time());
	if (get_time() > philo->limit)
		ft_dead(philo);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mutex);
}
