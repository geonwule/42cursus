#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

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

#include <limits.h>
#include <stdio.h>
int	main()
{
	ft_putnbr_fd(INT_MIN, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(INT_MAX, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);
}
