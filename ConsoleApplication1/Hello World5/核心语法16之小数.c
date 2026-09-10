#include <stdio.h>
int main()
{
//1、定义float、double、longdouble数据类型的变量
	//float 
	float a = 3.14F;
	printf("%f\n", a);
	printf("%.2f\n", a);

    //double
	double b = 1.78;
	printf("%lf\n", b);
	printf("%.2lf\n",b);

	//long doble 
	long double c = 3.1415926535L;
	printf("%Lf\n", c);//按道理来说终端上不是应该是取到小数点后10位吗？为什么只显示了6位呢？因为终端上默认只显示6位小数，如果想要显示更多位小数，可以使用格式控制符来指定显示的位数。

//2、利用sizeof测量出float、double、longdouble数据类型的变量的大小
	//float
	printf("%zu\n",sizeof( float));
	printf("%zu\n", sizeof(a));

	//double
	printf("%zu\n", sizeof(double));
	printf("%zu\n", sizeof(b));

	printf("%zu\n", sizeof(long double));
	printf("%zu\n", sizeof(c));

//3、小数的数据类型无法跟unsigned组合使用（这一段代码只是示例因此把它注注释掉了）
	/*usigned double d = 1.23;
	printf("%lf\n", d);*/
	return 0;
}