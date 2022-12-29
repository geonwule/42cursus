#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// s : the string from which to create the substring.
// start : the start index of the substring in the string 's'
// len : the maximum length of the substring
// return value : the substring. NULL if the allocation fails
// Description : allocates and returns a substring from the string 's'
// the substring begins at index 'start and is of maximum size 'len'
/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	s_len;

	s_len = strlen(s);
	if (start >= s_len)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
//		return (str);
		return (NULL);
	}
	if (len > s_len - start)	// 이게 관건
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	str[len] = '\0';
	strlcpy(str, s + start, len + 1);
	return (str);
}*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	str[len] = '\0';
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

int	main()
{
	char	s[] = "";
	
	printf("origin = %s, ft_substr("", 0, 0)  my string = %s pointer = %p\n", s, ft_substr(s, 0, 0), ft_substr(s, 0, 0));
	// apple = 0, 0 <- 길이 = 0 -> '\0'
}
