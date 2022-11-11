

// 파라미터 : 데이터를 복사할 주소이고, const char * 형으로 전달된다.
// 리턴값 : 복사된 데이터의 주소를 리턴하고 에러 발생시 NULL값이 리턴된다.
// strcpy에 추가적으로 메모리 할당을 해주는 함수이다. 
// 항상 strdup 사용 이후에 free가 필수이다.....

#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	const char	*s2;
	int			i;

	i = 0;
	s2 = (const char *)malloc(sizeof(const char) * ft_strlen(s1) + 1);
	if (s2 == '\0')
		return ('\0');
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

#include <stdio.h>
#include <string.h>

int	main()
{
	
}
