#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_utoa(unsigned int n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif
