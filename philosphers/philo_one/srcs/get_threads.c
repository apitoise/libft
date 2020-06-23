#include "../headers/philo_one.h"

void	*threads_func(t_philo *st, t_data *data, int i, pthread_t *tab)
{
	struct timeval	time;
	int				first;

	printf("%d is taking a fork.\n", i);
	st[i].begin = get_ms_time();
	printf("%d is eating.\n", i);
	usleep(data->eat * 1000);
	printf("%d is sleeping.\n", i);
	usleep(data->sleep * 1000);
	st[i].ret = get_ms_time();
	first = 0;
	if (st[i].ret < data->die - st[i].begin)
		printf("%d is thinking.\n", i);
	else
	{
		data->dead = 1;
		printf("%d is dead.\n", i);
		return (NULL);
	}
/*	while (st[i].ret < data->die - st[i].begin)
	{
		if (!first)
			printf("%d is thinking.\n", i);
		first = 1;
		st[i].ret = get_ms_time();
		if (st[i].ret < data->die - st[i].begin && i < data->nbphi)
			pthread_create(&tab[data->nbphi], NULL, threads_func(st, data, i + 1, tab), NULL);
	}
	if (st[i].ret < data->die - st[i].begin)
	{
		data->dead = 1;
		printf("%d is dead.\n", i);
		return (NULL);
	}*/
	return (NULL);
}

int		get_threads(t_philo *st, t_data *data)
{
	pthread_t	*tab;
	int			i;

	if (!(tab = malloc(data->nbphi * sizeof(pthread_t))))
		return (0);
	i = 1;
	while (i <= data->nbphi && data->dead == 0)
	{
		pthread_create(&tab[i], NULL, threads_func(st, data, i, tab), NULL);
		i++;
	}
	printf("OK\n");
	return (1);
}
