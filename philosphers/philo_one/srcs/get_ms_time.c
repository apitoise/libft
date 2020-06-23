#include "../headers/philo_one.h"

unsigned long	get_ms_time(void)
{
	static unsigned long	start;
	static int				init = 0;
	struct timeval			time;

	if (!init)
	{
		gettimeofday(&time, NULL);
		start = (time.tv_sec * 1000000 + time.tv_usec) / 1000;
		++init;
	}
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000 + time.tv_usec) / 1000 - start);
}
