//有符号整数、无符号整数的定义情况
//signed有符号整数 正数 负数
//unsigned无符号整数 只能是正数
#include <stdio.h>

   int main()
   {
	   signed int a = -10;
	   unsigned int b = 20;
	signed int c = 100;
	unsigned int d = -100;

	printf("%d\n", a);
	printf("%u\n", b);
	printf("%d\n", c);
	printf("%u\n", d);

	return 0;
   
   
   }