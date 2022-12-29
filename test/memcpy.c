//dest : 채우고자하는 메모리의 시작 포인터(시작주소)
//src : 메모리에 채우고자 하는 값, int형이지만 내부에서는 unsigned char(1 byte)로 변환되어서 저장된다.
//num : 채우고자하는 바이트의 수, 즉 채우고자하는 메모리의 크기
//memcpy 함수의 인자인 source가 가리키는곳부터 num 바이트 만큼을 destination이 가리키는곳에 복사한다.
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
/*	if (len == 0 || dest == src)
		return (dest);
	if (dest == 0 && src == 0)
		return (0);*/
	if (dest == 0 && src == 0)
		return (0);
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	d1[42];// = {'4', '2', 's', 'e', 'o', 'u', 'l', '!'};
	char	d2[42];// = {'4', '2', 's', 'e', 'o', 'u', 'l', '!'};
	char	b[42] = {'4', '2', 's', 'e', 'o', 'u', 'l', '!'};
	char	b2[42] = {'4', '2', 's', 'e', 'o', 'u', 'l', '!'};
	printf("origin d1 = %s\n origin d2= %s\n", b, b2);
//	printf("src = 42seoul!, memcpy = %s\n", memcpy(b, b, sizeof(char) * 4));
//	printf("src = 42seoul!, ft_memcpy = %s\n", ft_memcpy(b2, b2, sizeof(char) * 4));
//	printf("src = NULL, memcpy = %s\n", memcpy(b, (void *)0, 3));
//	printf("src = NULL, memcpy = %s\n", memcpy((void *)0, (void *)0, 3));
	printf("src = NULL, strcpy = %s\n", strncpy((void *)0, (void *)0, 3));
	printf("src = NULL, ft_memcpy = %s\n", ft_memcpy((void *)0, (void *)0, 3));

}
