int	ft_isalnum(int i)
{
	if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122)
		|| (i >= 48 && i <= 57))
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
                printf("isalnum(\'%c\') : %d\n", str[i], isalnum(str[i]));
                i++;
        }
		i = 0;
        while (i < max)
        {
                printf("ft_isalnum(\'%c\') : %d\n", str[i], ft_isalnum(str[i]));
                i++;
        }
}
