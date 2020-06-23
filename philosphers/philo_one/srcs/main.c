#include "../headers/philo_one.h"

int		ft_error(char *str)
{
	ft_putstr(str);
	return (-1);
}

int		main(int ac, char **av)
{
	t_philo			*st;
	t_data			data;
	struct timeval	time;
	int				tod;

	if (!(st = malloc(ft_atoi(av[1]) * sizeof(t_philo))))
		return (ft_error("Malloc error\n"));
	if (ac < 5)
		return (ft_error("Missing argument\n"));
	if (ac > 6)
		return (ft_error("Too many arguments\n"));
	if (!(get_data(ac, av, &data)))
		return (ft_error("Invalid arguments\n"));
	if (!(get_threads(st, &data)))
		return (ft_error("Malloc error\n"));
	return (0);
}