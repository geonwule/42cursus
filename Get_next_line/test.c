#include "get_next_line.h"

static char	*read_txt(char *back, char **n_ptr, int *readsize, int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static int	flag;

	while (1)
	{
		*readsize = read(fd, buf, BUFFER_SIZE);
		if (*readsize < 0 || (*readsize == 0 && flag++ == 0))
		{
			return (0);
		}
		if (*readsize == 0)
			break ;
		buf[*readsize] = '\0';
		back = ft_strjoin(back, buf);
		*n_ptr = ft_strchar(back, '\n');
		if (*n_ptr != NULL)
			break ;
	}
	return (back);
}

char	*ret_set(char *back, char *n_ptr)
{
	char	*ret;
	int		i;

	i = 0;
	while (back[i] != '\0')
	{
		if (&back[i] == n_ptr)
		{
			i++;
			break ;
		}
		i++;
	}
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (ret == NULL)
		return (0);
	ret[i] = '\0';
	ft_strlcpy(back, ret, i + 1);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*back;		//buffer back_up
	char		*n_ptr;		//n_line point
	char		*ret;		//result;
	int			readsize;

	readsize = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	back = read_txt(back, &n_ptr, &readsize, fd);
	if (back == NULL || *readsize == -1)
	{
		free(back);
		back = 0;
		return (0);
	}
	ret = ret_set(back, n_ptr);
	return (ret);
}

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int		fd;
	int		fd2;
	char	*gnl;
	char	*ret;

	fd = open("read_error.txt", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);

	int i = 2;
	printf("call num : %d\n", i);
	//1
	ret = get_next_line(fd);
	printf("%s\n, p = %p\n", ret, ret);
	free(ret);
	ret = get_next_line(fd);
	printf("%s\n p = %p\n", ret, ret);
	free(ret);
	//2
	ret = get_next_line(fd);
	printf("%s\n p = %p\n", ret, ret);
	free(ret);
	ret = get_next_line(fd);
	printf("%s\n p = %p\n", ret, ret);
	free(ret);
	system("leaks a.out");
}
