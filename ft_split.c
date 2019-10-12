#include "libft.h"

int		ft_countwords(char const *s, char c)
{
	int	res;
	int	new;

	res = 0;
	new = 1;
	while (*s)
	{
		if (*s != c && new == 1)
		{
			res++;
			new = 0;
		}
		if (*s == c)
			new = 1;
		s++;
	}
	return (res);
}


char		**ft_split(char const *s, char c)
{
	char	**res;
	int	idx;
	int	nb;
	int	len;
	int	cpy;

	res = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	idx = 0;
	nb = 0;
	len  = 0;
	while (s[idx])
	{
		while (s[idx] == c)
			idx++;
		while (s[idx + len] != c)
			len++;
		res[nb] = (char *)malloc((len + 1) * sizeof(char));
		cpy = 0;
		while (s[idx] != c && s[idx])
		{
			res[nb][cpy] = s[idx];
			idx++;
			cpy++;
		}
		res[nb][cpy] == '\0';
		nb++;
	}
	res[nb] = '\0';
	return (res);
}
