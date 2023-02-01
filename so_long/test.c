#include <stdio.h>

int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
	//return (t << 24 | r << 16 | g << 8 | b);
// << 이 부분이 bit 이동하는 부분임.
// | 8 | 8 | 8 | 8 | 
// 32  24  16  8       이런 구조가 있다고 생각하면
// t는 맨 앞 칸에, r은 두 번째 칸에, ...  이렇게 담김
}

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int main()
{
/*	unsigned char num1 = 1;
	unsigned char num2 = 3;

	printf("%d\n", num1 & num2);

	printf("%d\n", num1 | num2);*/
	int trgb;
	trgb = create_trgb(10, 7, 4, 1);
	printf("trgb = %d\n", trgb);
	printf("t = %d\n", get_t(trgb));
}
