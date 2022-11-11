#include <stdlib.h>

//dest = 채우고자하는 메모리의 시작 포인터 (시작주소)
//value = 메모리에 채우고자 하는 값, int형이지만 내부에서는 unsigned char(1byte)로 변환되어서 저장된다.
//count = 채우고자하는 바이트의 수. 즉, 채우고자하는 메모리의 크기
void	*ft_memset(void *dest, int value, size_t count)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)dest;
	i = 0;
	while (i < count)
	{
		temp[i] = (unsigned char)value;
		i++;
	}
	return (dest);
}

#include <string.h>
#include <stdio.h>

int	main()
{
	char	a[5]; // = {'1', '2', '3', '4', '5'};
	char	b[5]; // = {'1', '2', '3', '4', '5'};
	int		i = 0;

	printf("memset return = %s\n", memset(b, 65, sizeof(b)));
	printf("ft_memset return = %s\n", ft_memset(a, 65, sizeof(a)));
	while (i < (sizeof(b) / sizeof(char)))
	{
		printf("memset %d번째 = %c\n", i, a[i]);
		printf("ft_memset %d번째 = %c\n", i, b[i]);
		printf("===============\n");
		i++;
	}
}
