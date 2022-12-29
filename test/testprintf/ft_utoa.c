#include "printf.h"

static int	digit_check(unsigned int n)
{
	unsigned int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

void	insert_unsigned(char *ret, unsigned int n, int len)
{
	len--;
	while (len >= 0)
	{
		ret[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char	*ft_utoa(unsigned int n)
{
	char	*ret;
	int		ret_len;

	ret_len = digit_check(n);
	ret = (char *)malloc(sizeof(char) * ret_len + 1);
	if (ret == NULL)
		return (0);
	ret[ret_len] = '\0';
	insert_unsigned(ret, n, ret_len);
	return (ret);
}
