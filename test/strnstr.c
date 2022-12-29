#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	needle_check(const char *str, const char *nee, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while ((str[i + j] == nee[j]) && nee[j] != '\0' && i + j < len)
			j++;
		if (nee[j] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	index;

	index = needle_check(haystack, needle, len);
	if (needle[0] == '\0')
		return((char *)&haystack[0]);
	if (len == 0 || index == -1)	// needle이 공백이거나, 찾는 길이가 0이면 stack 자체 리턴
	return (0);
//		return ((char *)haystack);
	return ((char *)&haystack[index]);
}

int	main()
{
//	const char *hay = "teste";
//	const char *nee = "lorem";
	const char *hay = "";
	const char *nee = "";
	
	printf("str = %s, find = %s\n", hay, nee);
	printf("strnstr = %s, address = %p\n", strnstr(hay, nee, 2), strnstr(hay, nee, 2));
	printf("ft_strnstr = %s, address = %p\n", ft_strnstr(hay, nee, 2), ft_strnstr(hay, nee, 2));
//	printf("jjnstrnstr = %s\n", strnstr("\0", "hi", 0));
//	printf("jjjjjjstrnstr = %s\n", ft_strnstr("\0", "hi", 0));
}
