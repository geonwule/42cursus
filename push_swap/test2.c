#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int ac, char **av)
{
    printf("%lld\n", (((long long)22 + (long long)INT_MAX) / 2));
}