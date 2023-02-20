#include "so_long.h"

char *ft_strjoin_so(char const *s1, char const *s2)
{
	char *map;
	int s1_len;
	int s2_len;
	int i[2];

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s2[s2_len - 1] == '\n')
		s2_len -= 1;
	map = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (map == NULL)
		return (0);
	i[0] = -1;
	i[1] = -1;
	while (++i[0] < s1_len)
		map[i[0]] = s1[i[0]];
	while (++i[1] < s2_len)
		map[i[0] + i[1]] = s2[i[1]];
	map[s1_len + s2_len] = '\0';
	if (s1 != NULL)
		free((void *)s1);
	return (map);
}

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

static void	insert_int(char *ret, int n, int len)
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
		ret = ft_strdup_so("-2147483648");
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

char	*ft_strdup_so(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(sizeof(const char) * ft_strlen(s1) + 1);
	if (s2 == 0)
		return (0);
	while (s1[i] != 0)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}