#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int	idx;
	char	*res;

	idx = 0;
	if (!s || !f)
		return (0);
	res = (char *)malloc(ft_strlen((char *)s) * sizeof (char) + 1);
	if (res == 0)
		return (0);
	while (s[idx])
	{
		res[idx] = f(idx, s[idx]);
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
