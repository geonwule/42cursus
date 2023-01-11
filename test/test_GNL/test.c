#include "get_next_line.h"

#include <stdio.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1, char *back)
{
	char	*s2;
	int		i;

	i = 0;
	if (s1[i] == '\0')
	{
		free(back);
		return (0);
	}
	s2 = (char *)malloc(sizeof(const char) * ft_strlen(s1) + 1);
	if (s2 == 0)
		return (0);
	while (s1[i] != 0)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	free(back);
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	char	d;
	int		i;

	d = c;
	i = 0;
	if (s == NULL)
		return (0);
	if (d == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)&s[i]);
	}
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		i[2];

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (0);
	i[0] = -1;
	i[1] = -1;
	while (++i[0] < s1_len)
		str[i[0]] = s1[i[0]];
	while (++i[1] < s2_len)
		str[i[0] + i[1]] = s2[i[1]];
	str[s1_len + s2_len] = '\0';
	if (s1 != NULL)
		free((void *)s1);
//	free((void *)s2);
	return (str);
}

/////////////real
///
static char	*read_txt(char *back, char **n_ptr, int *readsize, int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static int	flag;

	*n_ptr = ft_strchr(back, '\n');
	while ((*n_ptr == NULL) && (*readsize != 0))
	{
		*readsize = read(fd, buf, BUFFER_SIZE);
		if (*readsize <= 0)
			break ;
		buf[*readsize] = '\0';
		back = ft_strjoin(back, buf);
		*n_ptr = ft_strchr(back, '\n');
	}
	return (back);
}

char	*ret_set(char *back, char **n_ptr)
{
	char	*ret;
	static char	*before_ret;
	int		i;

	i = 0;
	while (back[i] != '\0')
	{
		if (&back[i] == *n_ptr)
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
	ft_strlcpy(ret, back, i + 1);
	if (i == 0)
		return (0);
	before_ret = *n_ptr;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*back;		//buffer back_up
	char		*n_ptr;		//n_line point
	char		*ret;		//result;
	int			readsize;

	readsize = -2;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	back = read_txt(back, &n_ptr, &readsize, fd);
	printf("back = %s-----\n", back);
	if (back == NULL || readsize == -1)
	{
		free(back);
		back = 0;
		return (0);
	}
	ret = ret_set(back, &n_ptr);
	if (n_ptr != NULL)
	{
		back = ft_strdup(n_ptr + 1, back);
	}
	return (ret);
}

#include <fcntl.h>

int main()
{
	int		fd;
	char	*gnl;
	char	*ret;

	fd = open("test.txt", O_RDONLY);

	int i = 2;
	printf("call num : %d\n", i);
	//1
	char	buf[40];

	int	rs;

	for (int j = 0; j < 40; j++)
	{
		buf[j] = 'F';
	}
	rs = read(fd, buf, 40);
//	buf[rs] = '\0';
	printf("%s", buf);
/*	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	//2
	ret = get_next_line(fd);
	printf("%s\n p = %p\n", ret, ret);
	free(ret);
	ret = get_next_line(fd);
	printf("%s\n p = %p\n", ret, ret);
	free(ret);*/
//	system("leaks a.out");
}
