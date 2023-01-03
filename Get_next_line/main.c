#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int		fd;
	char	*gnl;

	fd = open("test.txt", O_RDONLY);

	gnl = get_next_line(fd);
	printf("gnl = %s\n", gnl);

	gnl = get_next_line(fd);
	printf("gnl = %s\n", gnl);

	gnl = get_next_line(fd);
	printf("gnl = %s\n", gnl);

	gnl = get_next_line(fd);
	printf("gnl = %s\n", gnl);
}
