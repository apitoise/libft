#include "../headers/philo_one.h"

uint64_t	get_time(void)
{
	static struct timeval	tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

int		main()
{
	long long	begin;

	begin = get_time();
	printf("%llu\n", get_time());
	usleep(1000000);
	printf("%llu\n", get_time());
	printf("%llu\n", get_time() - begin);
	return (0);
}
