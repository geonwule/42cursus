void	ft_bzero(void *s, int len)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (i < len)
	{
		temp[i] = 0;
		i++;
	}	
}

#include <stdio.h>
#include <string.h>

int	main()
{
	char	a[5]; // = {'1', '2', '3', '4', '5'};
	char	b[5]; // = {'1', '2', '3', '4', '5'};
	int		i = 0;

	bzero(a, sizeof(a));
	ft_bzero(b, sizeof(b));
	while (i < (sizeof(a) / sizeof(char)))
	{
		printf("bzero %d번째 = %d\n", i, a[i]);
		printf("ft_bzero %d번째 = %d\n", i, b[i]);
		printf("===============\n");
		i++;
	}
}
