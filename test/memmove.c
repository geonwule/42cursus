//dest : 채우고자하는 메모리의 시작 포인터(시작주소)
//src : 메모리에 채우고자 하는 값, int형이지만 내부에서는 unsigned char(1 byte)로 변환되어서 저장된다.
//num : 채우고자하는 바이트의 수, 즉 채우고자하는 메모리의 크기
//memcpy와 차이점 : memcpy는 어디 거치지않고 그 위치에 복사해서 붙여넣는것
//memmove는 그것보다 안전하게 복사할것을 버퍼에 복사하고 해당 위치에 가서 버퍼에 복사된것을 붙여넣는 식
//성능을 따지면 memcpy가 버퍼 거치지 않고 복사해서 좋긴 하겠지만 버퍼를 이용하는 memmove가 더 안정성이 좋다.
//
//-> memmove도 src에서 dst로 num바이트 긿이만큼 복사하는 함수이다.
//하지만, 중간에 버퍼를 이용해서 복사를 하므로 안정성이 memcpy보다는 뛰어나다.
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dp;
	unsigned char	*sp;

	dp = (unsigned char *)dest;
	sp = (unsigned char *)src;
	if (dest == 0 && src == 0)
		return (0);
	i = -1;
	if (dp <= sp)
	{
		while (++i < len)
			dp[i] = sp[i];
	}
	else if (dp > sp)
	{
		len--;
		while (++i <= len)
			dp[len - i] = sp[len - i];
	}
	return ((void *)dp);
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	array1[10] = {' ',' ','t','e','s','t'};
	char	array2[10] = {'t','e','s','t',' ',' '};
	ft_memmove(array1, array1 + 2, 4);
	ft_memmove(array2 + 2, array2, 4);
// 	char *src = "";
//	char *dst1 = "";
 //	int size = strlen(src);

//	ft_memmove(dst1, src - 1, 0);
//	ft_memmove(dst1, src - 1, size);
	printf("testst : %s\n", array1);
	printf("tetest : %s\n", array2);
}

/*
int	main()
{
//	char	d1[42];// = {'4', '2', 's', 'e', 'o', 'u', 'l', '!'};
//	char	d2[42];// = {'4', '2', 's', 'e', 'o', 'u', 'l', '!'};
	char	array[7] = {'t', 'e', 's', 't', ' ', ' ', '\0'};
//	char	bi[6] = {' ', ' ', 't', 'e', 's', 't'};
//	printf("origin d1 = %s\n origin d2= %s\n", b, b1);
//	char	*ptr = b + 2;
//	char	*ptr1 = b1 + 2;
//	printf("origin ptr = %s\n", ptr);
//	printf("origin ptr1 = %s\n", ptr1);
	memmove(array + 2, array, 4);
	printf("dst=test+2, src = test, count = 4  memmove = %s\n", array);
//	printf("dst=test+2, src = test, count = 4  ft_memmove = %s\n", ft_memmove(ptr1, b1, 4));
//	printf("src = 42seoul!, memmove = %s\n", memmove(b, ptr, 4));
//	printf("src = 42seoul!, ft_memmove = %s\n", ft_memmove(ptr1, b1, sizeof(b1)));

}*/
