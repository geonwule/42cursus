int	ft_atoi(char *str)
{
	int	i;
	int	flag;
	int	result;

	i = 0;
	result = 0;
	flag = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	result *= flag;
	return (result);
}

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
//	char	str[] = "---++42aass";

	char	*str = av[1];
	printf("atoi(%s) = %d\n", str, atoi(str));
	printf("ft_atoi(%s) = %d\n", str, ft_atoi(str));
}
