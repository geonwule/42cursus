#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void	file_init(char *av1, char *av2, char *file1, char *file2)
{
	file1 = (char *)malloc(sizeof(char) * (strlen(av1) + 1));
	if (file1 == NULL)
		exit(1);
	file2 = (char *)malloc(sizeof(char) * (strlen(av2) + 1));
	if (file1 == NULL)
		exit(1);
	strcpy(file1, av1);
	strcpy(file2, av2);
}

int main(int ac, char **av)
{
	char *file1, *file2;

	if (ac != 5)
	{
		printf("Error\n");
		return (0);
	}
	file_init(av[1], av[4], file1, file2);
	execve(file1, &av[2], NULL);
}
