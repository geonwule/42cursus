#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	backup[100000];
	char	buf;
	char	*str;
	int		i;
	int		read_size;
	i = 0;
	while (1)
	{
		read_size = read(fd, &buf, 1);
		if (read_size < 0 || (read_size == 0 && buf == '\0'))
			return (0);
		if (read_size == 0)
			break ;
		backup[i] = buf;
		i++;
		if (buf == '\n')
			break ;
	}
	backup[i] = '\0';
	str = (char *)malloc(sizeof(char) * (i + 1));
	while (i >= 0)
	{
		str[i] = backup[i];
		i--;
	}
	return (str);
}

int	main()
{
	int	fd = open("test.txt", O_RDONLY);

	for (int i = 0; i < 3; i++)
	{
	printf("%d = %s\n", i, get_next_line(fd));
	}
}
