#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	int	*i;
	int	j;

	i = (int *)malloc(size * count);
	if (i == NULL)
		return (0);
	j = 0;
	while (j < count)
	{
		i[j] = 0;
		j++;
	}
	return ((void *)i);
}

int	main()
{
	char *a;

	a = (char *)malloc(sizeof(char) * 10);
	for (int i = 0; i < 10; i++)
	{
		a[i] = 48 + i;
	}
	printf(" a = %s\n", a);

	free(a);

	char *b;

	b = (char *)ft_calloc(3, sizeof(char));
	for (int i = 0; i < 10; i++)
	{
	printf(" b =%d번째 :  %d\n", i, b[i]);
	}
	printf("\n");
	free(b);
}
