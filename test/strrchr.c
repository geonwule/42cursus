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

/*
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
*/

// strrchr는 strchr와 다르게 동일한 문자가 있을때 가장 나중거 체크
char	*ft_strrchr(const char *s, int c)
{
	char	d;
	char	*temp;
	int		flag;
	int		i;

	d = c;
	i = -1;
	flag = 0;
	if (d == '\0')
	{
		while (s[++i] != '\0');
		return ((char *)&s[i]);
	}
	while (s[++i] != '\0')
	{
		if (++flag >= 0 && s[i] == d)
			temp = (char *)&s[i];
	}
	if (flag != 0)
		return (temp);
	return (0);
}
int	main()
{
//	char	str[] = "FiSghting 42SeouSl";
//	char	str[] = "abbbbbbbbbbbbbbbbb";
	char	str[] = "\xc4\xab\xc5\x93\xcb\x99\xcb\x80\xcb\x98\xc2\xaf\xcb\x87\xc2\xb8\xc2\xaf.\xc5\x93\xc2\xab\xe2\x80\x98\xe2\x80\x93\xe2\x80\x93\xe2\x84\xa2\xc2\xaa\xe2\x80\xa2\xc2\xa1\xc2\xb6\xc2\xa2\xcb\x9c\xcb\x80";
	char	*ptr = strrchr(str, L'\xe2\x80\x93');
	char	*ptr2 = ft_strrchr(str, L'\xe2\x80\x93');

	printf("ptr = %p, ptr2 = %p\n", ptr, ptr2);
	if (ptr != 0)
	{
		printf("원형 : %s\n", str);
		printf("strrchr : 찾는문자 = %c, 찾은 후부터 문자열 = %s\n", *ptr, ptr);
		printf("ft_strrchr : 찾는문자 = %c, 찾은 후부터 문자열 = %s\n", *ptr2, ptr2);
	}
}
