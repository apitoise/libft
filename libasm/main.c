/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:52:07 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/24 21:44:02 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

extern size_t	ft_strlen(char *str);
extern char		*ft_strcpy(char *dest, char *src);
extern int		ft_strcmp(char *s1, char *s2);
extern ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
extern ssize_t	ft_read(int fd, void *buf, size_t nbyte);
extern char		*ft_strdup(const char *s1);

void	test_strlen(void)
{
	int		i;
	char	*str[5] = {
		"Salut",
		"4COUCOU je suis une longue phrase",
		"",
		"s",
		"42 c'est super, youpi cool"
	};
	i = 0;
	while(i < 5)
	{
		printf("str[%d] = %s\n ft_strlen = %zu\n", i, str[i], ft_strlen(str[i]));
		printf("str[%d] = %s\n strlen = %lu\n", i, str[i], strlen(str[i]));
		i++;
	}
}

void	test_strcpy(void)
{
	char	src[] = "Je suis plus courte que la dst";
	char	dst[] = "Je suis plus longue que la src.";
	char	*ptr;
	char	src2[] = "Je suis plus courte que la dst";
	char	dst2[] = "Je suis plus longue que la src.";
	char	*ptr2;

	ptr = ft_strcpy(dst, src);
	ptr2 = strcpy(dst2, src2);
	printf("ft_strcpy: %s\n", ptr);
	printf("strcpy: %s\n", ptr2);
}

void	test_strcmp(void)
{
	char	*s1[5] = {
		"ABCDEF",
		"",
		"afkjsdafsjoa",
		"ABCDEFGH",
		"SSS"
	};
	char	*s2[5] = {
		"ABCDFE",
		"sS",
		"soiofhiuf",
		"ABCDEFGH",
		""
	};
	int		i;

	i = 0;
	while(i < 5)
	{
		printf("ft_strcmp(s1[i], s2[i]): %d\n", ft_strcmp(s1[i], s2[i]));	
		printf("strcmp(s1[i], s2[i]): %d\n", strcmp(s1[i], s2[i]));	
		i++;
	}
}

int		main(void)
{
	char	str[] = "SALUTsdfDSF dsHIUGHF";
	char	str2[] = "SALUTsdfDSF dsHIUGHF";
	char	src[] = "couc";
	char	readtest[] = "srcs/ft_read.s";
	char	*ptr2;
	char	*ptr;
	int		fd;
	int		i;
	int		j;

	printf("==========[FT_STRLEN]==========\n");
	test_strlen();
	printf("==========[FT_STRCPY]==========\n");
	test_strcpy();
	printf("==========[FT_STRCMP]==========\n");
	test_strcmp();
	printf("==========[FT_WRITE]==========\n");
	printf("==========[FT_READ]==========\n");
	printf("==========[FT_STRDUP]==========\n");
	i = 0;
	fd = open(readtest, O_RDONLY);
	i = read(fd, &str, ft_strlen(str));
	close(fd);
	fd = open(readtest, O_RDONLY);
	j = read(fd, &str2, ft_strlen(str2));
	close(fd);
	printf("i: %d\nj: %d\n", i, j);
	printf("ft_strcmp: %d\n", ft_strcmp(str, src));
	ptr = ft_strcpy(str, src);
	printf("ft_strlen: %zd\n", ft_strlen(str));
	printf("str = [%s], ptr = [%s]\n", str, ptr);
	printf("ft_write(1, &str, len): \n");
	printf("\nret ft_write: %zd\n", ft_write(1, &str, ft_strlen(str)));
	ptr2 = ft_strdup(readtest);
	printf("ptr2: %s\n", ptr2);
	return (0);
}
