#include <stdio.h>

void	check_to(void)
{
	static int	i = 0;
	printf("%d\n", i);
	i++;
}

int	main()
{
	check_to();
	check_to();
	check_to();
}
