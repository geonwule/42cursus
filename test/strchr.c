#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// 문자열 내에 일치하는 문자가 있는지 검사하는 함수
// s = 검색할 문자열
// c = 존재하는지 확인할 문자 ( 아스키 값으로 들어감 )
// 검사후에 해당문자가 존재하면 해당문자 존재하는곳의 포인터를 반환,
// 존재하지 않으면 널 포인터 반환
//
// 함수사용 예시


char	*ft_strchr(const char *s, int c)
{
	char	d;
	int		i;

	d = c;
	i = 0;

	if (d == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)&s[i]);
	}
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

int	main()
{
	char	str[] = "Fighting 42Seoul";
	char	*ptr = strchr(str, 32);
	char	*ptr2 = ft_strchr(str, 32);

	printf("ptr = %p, ptr2 = %p\n", ptr, ptr2);
	if (ptr != 0)
	{
		printf("원형 : %s\n", str);
		printf("strchr : 찾는문자 = %c, 찾은 후부터 문자열 = %s\n", *ptr, ptr);
		printf("ft_strchr : 찾는문자 = %c, 찾은 후부터 문자열 = %s\n", *ptr2, ptr2);
	}
}
