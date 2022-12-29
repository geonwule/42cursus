#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// piscine
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (n == 0)
		return (0);
	if (i == n)
		i--;
	return (s1[i] - s2[i]);
}
// born
/*
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if (n == 0 || i == n)	// n = 0 비교할게 없거나, i == n  문자가 똑같을때 0 반환
		return (0);
	return (s1[i] - s2[i]);
}
*/
int	main()
{
	char	*s1 = "test\200";
	char	*s2 = "test\0";

	printf("s1 = %s, s2 = %s\n", s1, s2);
	printf("strncmp = %d, ft_strncmp = %d\n", strncmp(s1, s2, 6), ft_strncmp(s1, s2, 6));
}
