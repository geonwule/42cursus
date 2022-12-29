#include <stdlib.h>
#include <stdio.h>

int	ret_len_cnt(unsigned int i)
{
	int	len;

	len = 0;
	if (i == 0)
		return (1);
	while (i)
	{
		len++;
		i /= 16;
	}
	return (len);
}

char	*low_hex(unsigned int i)
{
	char	*hex;
	char	*ret;
	int		ret_len;

	hex = "0123456789abcdef";
	ret_len = ret_len_cnt(i);
	ret = (char *)malloc(sizeof(char) * (ret_len + 1));
	if (ret == NULL)
		return (0);
	ret[ret_len] = '\0';
	ret_len--;
	while (ret_len >= 0)
	{
		ret[ret_len] = hex[i % 16];
		i /= 16;
		ret_len--;
	}
	return (ret);
}

#include <unistd.h>
#include <string.h>
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, strlen(s));
}


int	main()
{
	char		*ret;
	char		*s;
	char		c;
	int			i;
	unsigned int u;

	ret = low_hex((unsigned int)&s);
	printf("ret = %s\n", ret);
	if ((unsigned int)&s == 0)
	{
		printf("0x0\n");
		printf("\n real : %p\n", &s);
		return (0);
	}
	write(1, "0x7ffe", 5);
	ft_putstr_fd(ret, 1);
	printf("\n real : %p\n", &s);
}
