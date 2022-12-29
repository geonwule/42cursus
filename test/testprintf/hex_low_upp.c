
#include "printf.h"

void	low_hex(char *n)
{
	char	*low_g;
	char	*ret;
	int		len;
	int		i;

	low_g = "0123456789abcdef";
	len = ft_strlen(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (0);
	ret[len] = '\0';
	i = 0;
	while (i < len)
	{
		ft_putchar_fd(low_g[n / 16]);
		ft_putchar_fd(low_g[n % 16]);
		i++;
	}
}
