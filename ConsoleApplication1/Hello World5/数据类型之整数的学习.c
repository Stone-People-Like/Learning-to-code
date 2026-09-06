#include <stdio.h>

int main()
{ 
	//1、定义short和int和long和long long类型的变量，并打印出它们的大小
   
	//short 短整型 windows 2字节
	short a = 10;
	printf("%d\n", a);

	//int 整型 windows 4字节
	int b = 100;
	printf("%d\n", b);

	//long 长整型 windows 4字节 Linux 32位 4字节 Linux 64位 8字节
	long c = 1000L;
	printf("%ld\n", c);

	//long long 长长整型 windows 8字节
	long long d = 1000LL;
	printf("%lld\n", d);


	//2、利用sizeof测量出short和int和long和long long类型的变量的大小
	//sizeof(变量名/数据类型)
	//short
	printf("%zu\n", sizeof(short));
	printf("%zu\n", sizeof(a));

	//int
	printf("%zu\n", sizeof(int));
	printf("%zu\n", sizeof(b));

	//long
	printf("%zu\n", sizeof(long));
	printf("%zu\n", sizeof(c));

	//long long
	printf("%zu\n", sizeof(long long));
	printf("%zu\n", sizeof(d));

	return 0;
}