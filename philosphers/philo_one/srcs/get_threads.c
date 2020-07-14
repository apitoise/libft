/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:13:58 by apitoise          #+#    #+#             */
/*   Updated: 2020/07/14 16:15:11 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_one.h"


void	*threads_func(void *arg)
{
	t_philo			*philo;
	unsigned long	limit;
	struct timeval	time;

	philo = (t_philo *)arg;
//	philo->limit = get_ms_time() + (philo->data.die * 1000);
	while (1 && !philo->dead)
	{
		pthread_mutex_lock(&philo->mutex);
		philo->is_eating = 1;
		philo->limit = get_time() + (philo->data.die * 1000);
		ft_forks(philo);
		ft_eat(philo);
		ft_sleep(philo);
		philo->is_eating = 0;
		pthread_mutex_unlock(&philo->mutex);
	}
	return (NULL);
/*	usleep(philo->data.eat * 1000);
	if (get_ms_time() > philo->limit)
	{
		philo->data.dead = 1;
		printf("%d is dead\n", philo->id);
		return (NULL);
	}
	printf("%d is sleeping.\n", philo->id);
	usleep(philo->data.sleep * 1000);
	philo->ret = get_ms_time();
	if (get_ms_time() < philo->limit)
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
	return (NULL);*/
}

int		get_threads(t_philo *philo)
{
	int		i;
	void	*phi;

	pthread_mutex_init(&philo->mutex, NULL);
	i = 1;
	while (i <= philo->data.nbphi)
	{
		philo[i].begin = get_time();
		i++;
	}
	printf("%lu\n", philo[1].begin);
	i = 1;
	philo->dead = 0;
	philo->is_eating = 0;
	while (i <= philo->data.nbphi && !philo->dead)
	{
		philo[i].id = i;
		pthread_create(&philo[i].thread, NULL, threads_func, &philo[i]);
		//pthread_detach(philo[i].thread);
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
