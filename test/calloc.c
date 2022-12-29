#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*i;
	size_t	j;

	i = (size_t *)malloc(size * count);
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
	char	*ex_char;
	char	*ex_char2;
	int		*ex_int;
	int		*ex_int2;

	ex_char = (char *)calloc(3, sizeof(char));
	ex_char2 = (char *)ft_calloc(3, sizeof(char));
	ex_int = (int *)calloc(3, sizeof(int));
	ex_int2 = (int *)ft_calloc(3, sizeof(int));

	printf("calloc ex_char : ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d번째 : %d, ", i, ex_char[i]);
	}
	printf("\n");
	printf("ft_calloc ex_char : ");
	for(int i = 0; i < 10; i++)
	{	
		printf("%d번째 : %d, ", i, ex_char2[i]);
	}
	printf("\n");
	free(ex_char);
	free(ex_char2);
	//free(ex_int);
	//free(ex_int2);
}
