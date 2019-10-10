#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int	size;
	char	*res;
	int	cpy;

	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	res = (char *)malloc(size * sizeof(char) + 1);
	if (res == 0)
		return (0);
	cpy = 0;
	while (*s1)
	{
		res[cpy] = *s1;
		cpy++;
		s1++;
	}
	while (*s2)
	{
		res[cpy] = *s2;
		cpy++;
		s2++;
	}
	res[cpy] = '\0';
	return (res);
}
