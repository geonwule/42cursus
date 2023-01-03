#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	d;
	int		i;

	d = c;
	i = 0;
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

	src_len = strlen(src);
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

char	*get_next(char *dic)
{
	static char *back;
	static int	flag = 0;
	static int	i = 0;
	int			k = 0;
	int			len = 0;
	char		*ret;
	
	if (flag == 0)
	{
		back = (char *)malloc(sizeof(char) * (strlen(dic) + 1));
		ft_strlcpy(back, dic, strlen(dic) + 1);	
	}
	if (back[i] == '\0')
		return (0);
	while (back[i] != '\n' && back[i] != '\0')
	{
		i++;
		len++;
	}
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (0);
	ft_strlcpy(ret, &back[i - len], len + 1);
	while (back[i] == '\n' && back[i] != '\0')
		i++;
	flag++;
	return (ret);
}

int	main()
{
	char	*dic = "42\nF\n\ngoo";

	printf("%s\n",	get_next(dic));
	printf("%s\n",	get_next(dic));
	printf("%s\n",	get_next(dic));

	return (0);
}
