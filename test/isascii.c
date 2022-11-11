int	ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (1);
	else
		return (0);
}

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int    main()
{
        char    str[] = "42Seoul!+#";
        int             i = 0;
        int             max = strlen(str);

        while (i < max)
        {
                printf("isascii(\'%c\') : %d\n", str[i], isascii(str[i]));
                i++;
        }
		i = 0;
        while (i < max)
        {
                printf("ft_isascii(\'%c\') : %d\n", str[i], ft_isascii(str[i]));
                i++;
        }
}
