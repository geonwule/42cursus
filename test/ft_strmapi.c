
#include <stdlib.h>
#include <string.h>
//s : string on which to iterate
//f : function to apply to each character
//return : string created from the successive applications of f
//return NULL if the allocation fails
//des : applies the function f to each character of the string s, and passing its index as first
//argument to create a new string resulting from successive applications of f
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	ret_len;
	unsigned int	i;

	ret_len = strlen(s);
	ret = (char *)malloc(sizeof(char) * (ret_len + 1)); // ft
	if (ret == NULL)
		return (0);
	ret[ret_len] = '\0';
	i = 0;
	while (s[i] != '\0')
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	return (ret);
}

#include <stdio.h>

char	to_up_char(unsigned int i, char c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

int	main()
{
	char *s  = "abCdEfGhI";
	char *new = ft_strmapi(s, &(to_up_char));

	printf("new = %s\n", new);
}
