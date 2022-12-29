#include <ctype.h>
#include <stdio.h>
#include <string.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

int	main()
{
	char *s = "abcdABCD";
	char *s2 = "abcdABCD";

	printf("s origin = %s\n", s);

	int max = strlen(s);

	int	i = 0;
/*	while (i < max)
	{
		tolower(s[i]);
		printf("tolower = %c\n", s[i]);
		i++;
	}*/
/////////////////////////////////////
	i = 0;
	while (i < max)
	{
		printf("ft_tolower = %c\n", ft_tolower(s2[i]));
		i++;
	}
/*	i = 0;
	//////////////
	while (i < max)
	{
		toupper(s[i]);
		printf("toupper = %c\n", s[i]);
		i++;
	}*/
	i = 0;
	//////////////////////////
/*	while (i < max)
	{
		ft_toupper(s2[i]);
		printf("ft_toupper = %c\n", s[i]);
		i++;
	}*/
}
