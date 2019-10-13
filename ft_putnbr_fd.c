#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		nbr = nb * -1;
		ft_putchar_fd('-', fd);
	}
	else
		nbr = nb;
	if (nb >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + 48, fd);
	}
	if (nb < 10)
		ft_putchar_fd(nbr + 48, fd);
}
