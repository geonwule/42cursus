#include <stdio.h>
#include <unistd.h>
#include "./includes/ft_printf.h"

int ft_check(const char *format, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, format);

    // unsigned char c;
    // char *c;
    int c;
    // int *c;

    c = va_arg(ap, int);
    printf("%d\n", c);
    if (!c)
    {
        write(2, "Error\n", 6);
        return (0);
    }
    return (1);

    va_end(ap);
}

int main()
{
    int i = 1;


    // ft_check("my printf fucking%d", "hh");
    // write(1, "write\n", 6);

   // printf("my printf%d", "ok");
    ft_printf("my printf%d", "ok");
    // write(1, "write\n", 6);
}