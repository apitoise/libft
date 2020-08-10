/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:13:58 by apitoise          #+#    #+#             */
/*   Updated: 2020/07/16 16:43:06 by apitoise         ###   ########.fr       */
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
	while (!philo->dead)
	{
		philo->is_eating = 1;
		philo->limit = get_time() + (philo->data.die * 1000);
		ft_forks(philo);
		ft_eat(philo);
		ft_sleep(philo);
		philo->is_eating = 0;
	}
	return (NULL);
}

int		get_threads(t_philo *philo)
{
	int		i;
	void	*phi;

	pthread_mutex_init(&philo->mutex, NULL);
	pthread_mutex_init(&philo->eat_m, NULL);
	pthread_mutex_init(&philo->write, NULL);
	i = 0;
	while (i < philo->data.nbphi)
	{
		philo[i].begin = get_time();
		printf("philo[%d].begin = %lu\n", i + 1, philo[i].begin);
		i++;
	}
	i = 0;
	philo->dead = 0;
	philo->is_eating = 0;
	while (i < philo->data.nbphi && !philo->dead)
	{
		philo[i].id = i + 1;
		printf("philo[%d].id = %d\n", i, philo[i].id);
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
