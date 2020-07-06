/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:13:58 by apitoise          #+#    #+#             */
/*   Updated: 2020/07/06 16:21:24 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_one.h"


void	*threads_func(void *arg)
{
	t_philo			*philo;
	unsigned long	limit;
	struct timeval	time;

	philo = (t_philo *)arg;
	philo->begin = get_ms_time();
	printf("%d is taking a fork.\n", philo->id);
	printf("%d is eating.\n", philo->id);
	limit = get_ms_time() + (philo->data.die * 1000);
	usleep(philo->data.eat * 1000);
	if (get_ms_time() > limit)
	{
		philo->data.dead = 1;
		printf("%d is dead\n", philo->id);
		return (NULL);
	}
	printf("%d is sleeping.\n", philo->id);
	usleep(philo->data.sleep * 1000);
	philo->ret = get_ms_time();
	if (get_ms_time() < limit)
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
	void	*phi;

	i = 1;
	while (i <= philo->data.nbphi && philo->data.dead == 0)
	{
		philo[i].id = i;
		pthread_create(&philo[i].thread, NULL, threads_func, &philo[i]);
		i++;
	}
	i = 1;
	while (i <= philo->data.nbphi)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	printf("OK\n");
	return (1);
}
