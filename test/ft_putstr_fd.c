
#include <unistd.h>
#include <string.h>
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, strlen(s)); // ft
}

int	main()
{
	ft_putstr_fd("Hello 42seoul", 1);
}
