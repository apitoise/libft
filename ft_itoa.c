#include "libft.h"

int		ft_len(int n)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		res++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int	len;
	int	idx;

	len = ft_len(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	idx = 0;
	if (n < 0)
	{
		res[idx] = '-';
		idx++;
		n = n * -1;
	}
	while (n > 0)
	{
		res[idx] = (n % 10) + 48;
		n = n / 10;
		idx++;
	}
	if (n == 0)
	{
		res[idx] = '0';
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
