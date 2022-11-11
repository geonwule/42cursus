int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	else
		return (0);
}

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int    main()
{
        char    str[] = "42Seoul!+#\v\n\t";
        int             i = 0;
        int             max = strlen(str);

        while (i < max)
        {
                printf("isprint(\'%c\') : %d\n", str[i], isprint(str[i]));
                i++;
        }
		i = 0;
        while (i < max)
        {
                printf("ft_isprint(\'%c\') : %d\n", str[i], ft_isprint(str[i]));
                i++;
        }
}
