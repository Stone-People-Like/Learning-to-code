#include<stdio.h>

int main()
{
	//1.定义char数据类型的变量
	//char 字符 取值范围ASCII码表中所有的内容 windows中占1个字节
	char c1 = 'a';
	printf("%c\n", c1);

	char c2 = '1';
	printf("%c\n", c2);

	char c3 = 'A';
	printf("%c\n", c3);

	char c4 = '.';
	printf("%c\n", c4);

	//2.利用sizeof测量出char数据类型的变量的大小
	printf("%zu\n", sizeof(char));
	printf("%zu\n", sizeof(c1));

	return 0;
}