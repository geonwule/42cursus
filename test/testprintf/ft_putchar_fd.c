#include <unistd.h>

// c = the character to output
// fd = the file descriptor on which to write
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
