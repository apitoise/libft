#include "../headers/philo_one.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_atoi(const char *str)
{
	unsigned long	res;
	int				neg;
	int				pos;

	pos = 0;
	if ((str[pos] >= 'a' && str[pos] <= 'z') || (str[pos] >= 'A' && str[pos] <= 'Z'))
		return (0);
	neg = 1;
	if (str[pos] == '+' || str[pos] == '-')
	{
		if (str[pos] == '-')
			neg++;
		pos++;
	}
	if ((str[pos] >= 'a' && str[pos] <= 'z') || (str[pos] >= 'A' && str[pos] <= 'Z'))
		return (0);
	res = 0;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		res = res * 10;
		res = res + str[pos] - 48;
		pos++;
	}
	if ((str[pos] >= 'a' && str[pos] <= 'z') || (str[pos] >= 'A' && str[pos] <= 'Z'))
		return (0);	
	if (neg % 2 == 0)
		return (-res);
	return (res);
}
