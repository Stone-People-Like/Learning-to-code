//练习：分别用二进制、八进制、十进制和十六进制表示数字 12，并打印出来。
#include <stdio.h>
int main()
{
	int a = 0b1100; 
	printf("%d\n", a);// 二进制表示

	int b = 014; 
	printf("%d\n", b);// 八进制表示

	int c = 12; 
	printf("%d\n", c);// 十进制表示

	int d = 0xC; 
	printf("%d\n", d);// 十六进制表示

	return 0;
}