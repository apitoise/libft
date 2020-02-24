/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:52:07 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/24 19:02:51 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

extern size_t	ft_strlen(char *str);
extern char		*ft_strcpy(char *dest, char *src);
extern int		ft_strcmp(char *s1, char *s2);
extern ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
extern ssize_t	ft_read(int fd, void *buf, size_t nbyte);
extern char		*ft_strdup(const char *s1);

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
