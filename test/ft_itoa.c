#include <stdlib.h>
#include <string.h>
//n : the integar to convert
//return : string representing the integer.
//NULL if the allocation fails
//Allocates and returns a string representing the integer received as an argument. 
//Negative numbers must be handled

static int	digit_check(int n)
{
	int	cnt;

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

void	insert_int(char *ret, int n, int len)
{
	len--;
	while (len >= 0)
	{
		ret[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		ret_len;

	if (n == -2147483648)
	{
		ret = strdup("-2147483648"); //ft
		return (ret);
	}
	if (n < 0)
		ret_len = digit_check(-n) + 1;
	else
		ret_len = digit_check(n);
	ret = (char *)malloc(sizeof(char) * ret_len + 1);
	if (ret == NULL)
		return (0);
	ret[ret_len] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		insert_int(ret + 1, -n, ret_len - 1);
	}
	else
		insert_int(ret, n, ret_len);
	return (ret);
}

#include <limits.h>
#include <stdio.h>
int	main()
{
	int	i = -42;
	char	*s;

	s = ft_itoa(INT_MIN);
	printf("answer = %d :  %s\n",INT_MIN, s);
	free (s);
}
