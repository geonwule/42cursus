#include <stdlib.h>
#include <string.h>

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static int	word_count2(char const *s, char c, int i)
{
	int	origin_i;

	origin_i = i;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i - origin_i);
}

static char	*word_set(char const *s, char c, int idx)
{
	char	*result;
	int		result_len;

	result_len = word_count2(s, c, idx);
	result = (char *)malloc(sizeof(char) * (result_len + 1));	//protection check for 2th malloc
	if (result == NULL)
		return (0);
	result[result_len] = '\0';
	strlcpy(result, s + idx, result_len + 1);
	return (result);
}

void	free_split(char **result, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		result_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result_len = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (result_len + 1));
	if (result == NULL)
		return (0);
	result[result_len] = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			if (!(result[j] = word_set(s, c, i)))
			{
				free_split(result, j);
				return (0);
			}
			j++;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (result);
}

#include <stdio.h>
#include <string.h>
int	main()
{
	char	**spi;
	int		i = -1;

	spi = ft_split("xxxxxxxxhello!", 'x');
	while (spi[++i])
	{
		printf("%s\n", spi[i]);
	}
}
