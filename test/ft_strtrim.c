#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//s1 = the string to be trimmed
//set = the reference set
//return = trimmed string. Null if the allocation fails
//Description : allocate and returns a copy of 's1' 
//with the characters specified in 'set' removed from the beginning and the end of the string

static int	set_check(const char s, char const *set)
{
	int	i;
	i = 0;
	while (set[i] != '\0')
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		start;
	int		end;

	end = strlen(s1) - 1; // ft
	i = 0;
	while (i <= end && set_check(s1[i], set))
		i++;
	if (s1[i] == '\0')
		return (strdup(""));
	start = i;
	i = end;
	while (i >= 0 && set_check(s1[i], set))
		i--;
	end = i;
	new = (char *)malloc(sizeof(char) * end - start + 2);
	if (new == NULL)
		return (0);
	new[end - start + 1] = '\0';
	strlcpy(new, s1 + start, end - start + 2);
	return (new);
}

int	main()
{
	char	a[] = "aa b cc ttttttbbbb aalllaa";
	char	b[] = "a bc";
 //	char *a = "  \t \t \n   \n\n\n\t";
// 	char *b = " \n\t";
	char	*new = ft_strtrim(a, b);

	printf("a = %s, b = %s, my = %s\n", a, b, new);
}
