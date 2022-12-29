#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"
void	*memchr(const void *s, int c, size_t n);
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return ((void *)0);
}
