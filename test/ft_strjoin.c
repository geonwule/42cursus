#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// s1 : the prefix string
// s2 : the suffix string
// return : new string, Null if the allocation fails
// Description : allocates and returns a new string, which is the result of the concatenation of s1 and s2.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	s1_len = strlen(s1);
	s2_len = strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (0);
	strlcpy(str, s1, s1_len + 1);
	strlcpy(str + s1_len, s2, s2_len + 1);
	str[s1_len + s2_len] = '\0';
	return (str);
}

int	main()
{
	char	s1[] = "";
	char	s2[] = "slkdjalksd";
	char	*ss;

	ss = ft_strjoin(s1, s2);
	printf("answer = Star Basford, myaddress = %p, my string = %s\n", ss, ss);
	free(ss);
}
