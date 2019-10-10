#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int	size;
	
	size = 0;
	while (s[start + size])
		size++;
	if (size > len)
		size = len;
	res = malloc(size * sizeof(char) + 1);
	if (res = 0)
		return (NULL);
	while (len)
	{
		*res = s[start];
		res++;
		start++;
		len--;
	}
	*res = '\0';
	return (res);
}
