#include "printf.h"

static void	recul_nbr(int n, int fd)
{
	int	m;

	m = n;
	if (n)
	{
		recul_nbr(m /= 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	i;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", ft_strlen("-2147483648"));
		return ;
	}
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	i = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		recul_nbr(-n, fd);
	}
	else
		recul_nbr(n, fd);
}
