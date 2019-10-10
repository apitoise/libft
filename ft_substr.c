//#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int	cpy;
	
	if (*s == 0)
		return (0);
	res = (char *)malloc(len * sizeof(char) + 1);
	if (res == 0)
		return (NULL);
	cpy = 0;
	while (len)
	{
		res[cpy] = s[start];
		cpy++;
		start++;
		len--;
	}
	res[cpy] = '\0';
	return (res);
}

int		main()
{
	char const *str = "Salut a tous les amis";

	printf("%s", ft_substr(str, 9, 5));
	return (0);
}
