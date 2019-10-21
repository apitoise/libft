#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 3000

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	char	*filedes[BUFFER_SIZE + 1];
	int	fd;
	int	ret;
	int	i;
	int	len;

	len = 0;
	fd = open(av[1], O_RDONLY);
	ret = read(fd, &filedes, BUFFER_SIZE);
	*filedes = malloc(1);
	filedes[fd][ret] = '\0';
	close(fd);
	while (filedes[ret - 2] != 0)
	{
		ft_putchar(filedes[fd][ret - 2]);
		ret--;
	}
	return (0);
}
