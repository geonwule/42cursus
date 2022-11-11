int	ft_isalpha(int i)
{
	if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
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
                printf("isalpha(\'%c\') : %d\n", str[i], isalpha(str[i]));
                i++;
        }
		i = 0;
        while (i < max)
        {
                printf("ft_isalpha(\'%c\') : %d\n", str[i], ft_isalpha(str[i]));
                i++;
        }
}
