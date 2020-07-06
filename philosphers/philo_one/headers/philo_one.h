#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef	struct		s_data
{
	int				nbphi;
	int				eat;
	int				die;
	int				dead;
	int				sleep;
	int				eatmax;
	int				count;
}					t_data;

typedef	struct		s_philo
{
	int				id;
	unsigned long	begin;
	unsigned long	ret;
	pthread_t		thread;
	t_data			data;
}					t_philo;

int				main(int ac, char **av);
void			ft_putstr(char *str);
void			ft_putchar(char c);
int				get_data(int ac, char **av, t_data *data);
int				get_threads(t_philo *philo);
int				ft_atoi(const char *str);
unsigned long	get_ms_time(void);
