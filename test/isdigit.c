int	ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
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
                printf("isdigit(\'%c\') : %d\n", str[i], isdigit(str[i]));
                i++;
        }
		i = 0;
        while (i < max)
        {
                printf("ft_isdigit(\'%c\') : %d\n", str[i], ft_isdigit(str[i]));
                i++;
        }
}
