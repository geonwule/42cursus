#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"


int	main()
{
	printf("------test 1----------\n");


	printf("--return-->%d\n", printf("%p", (void *)-14523));
	printf("\n^^ printf --- vv ft_printf\n");
	ft_printf("--return-->%d\n", ft_printf("%p", (void *)-14523));

	printf("\n");
//	system("leaks a.out");
}
/*
	printf("------test 1----------\n");
	printf("\n^^ printf --- vv ft_printf\n");
	printf("\n");*/
