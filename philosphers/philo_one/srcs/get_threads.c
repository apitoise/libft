/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:13:58 by apitoise          #+#    #+#             */
/*   Updated: 2020/07/01 16:37:01 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_one.h"


void	*threads_func(void *arg)
{
	t_philo			*philo;
	struct timeval	time;

	philo = (t_philo *)arg;
	printf("%d\n", philo->id);
	printf("%d is taking a fork.\n", philo->id);
	philo->begin = get_ms_time();
	printf("%d is eating.\n", philo->id);
	usleep(philo->data.eat * 1000);
	printf("%d is sleeping.\n", philo->id);
	usleep(philo->data.sleep * 1000);
	philo->ret = get_ms_time();
	if (philo->ret < philo->data.die
			- philo->begin)
	{
		printf("%d is thinking.\n", philo->id);
		threads_func(philo);
	}
	else
	{
		philo->data.dead = 1;
		printf("%d is dead.\n", philo->id);
		return (NULL);
	}
	return (NULL);
}

int		get_threads(t_philo *philo)
{
	int		i;

	i = 1;
	while (i <= philo->data.nbphi && philo->data.dead == 0)
	{
		philo[i].id = i;
		pthread_create(philo[i].thread, NULL, threads_func, &philo[i]);
		i++;
	}
	i = 1;
	while (i <= philo->data.nbphi)
	{
		pthread_join(*philo[i].thread, NULL);
		i++;
	}
	printf("OK\n");
	return (1);
}
