#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int	main()
{
	int		fd;
	char	*gnl;
	char	*ret;

	fd = open("test.txt", O_RDONLY);

	int i = 2;
	printf("call num : %d\n", i);
	//1
	ret = get_next_line(fd);
	printf("%s\n", ret);
	free(ret);
	ret = get_next_line(fd);
	printf("%p\n", ret);
	free(ret);
	//2
	ret = get_next_line(fd);
	printf("%p\n", ret);
	free(ret);
	//3
	ret = get_next_line(fd);
	printf("%p", ret);
	free(ret);
/*	//4
	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	//5
	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	//6
	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);*/
//	system("leaks a.out");
}
