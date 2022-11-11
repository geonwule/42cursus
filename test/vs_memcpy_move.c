#include <string.h>
#include <stdio.h>

int	main()
{
	char	d11[] = "aaaaabbbbbdddddd";
	char	d12[] = "aaaaabbbbbdddddd";
	char	d21[] = "aaaaabbbbbdddddd";
	char	d22[] = "aaaaabbbbbdddddd";
	char	d31[] = "aaaaabbbbbdddddd";
	char	d32[] = "aaaaabbbbbdddddd";
	char	s1[] = "42Seoul";
	char	s2[] = "42Seoul";

	//src 길이 만큼만 복사
	printf("memcpy = %s\n memmove = %s\n", memcpy(d11, s1, sizeof(s1) - 1), memmove(d12, s1, sizeof(s1) - 1));

	//src 길이 + 1 복사
	printf("memcpy = %s\n memmove = %s\n", memcpy(d21, s1, sizeof(s1)), memmove(d22, s1, sizeof(s1)));

	//자기자신
	printf("자기자신 복사 memcpy = %s\n 자기자신 복사 memmove = %s\n", memcpy(s1, s1 + 2, sizeof(char) * 4), memmove(s2, s2 + 2, sizeof(char) * 4));
}
