void	ft_bbzero(void *s, int len)
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

void	ft_bzero(void *s, int len)
{
	char	*temp;

	temp = (char *)s;
	while (len--)
	{
		*temp = 0;
		temp++;
	}	
}


#include <stdio.h>
#include <string.h>

int	main()
{
	char	a[6] = {'1', '2', '3', '4', '5', '\0'};
	char	b[6] = {'1', '2', '3', '4', '5', '\0'};
	int		i = 0;

	printf("origin a = %s\n, b=%s\n", a, b);
	bzero(a, sizeof(a));
	ft_bzero(b, sizeof(b));
	printf("change a = %s\n, b=%s\n", a, b);
	while (i < (sizeof(a) / sizeof(char)))
	{
		printf("bzero %d번째 = %d\n", i, a[i]);
		printf("ft_bzero %d번째 = %d\n", i, b[i]);
		printf("===============\n");
		i++;
	}
}
