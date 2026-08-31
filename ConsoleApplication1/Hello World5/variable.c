#include<stdio.h>

int main()
{  //练习1：两个数相加
  //需求：定义两个变量分别储存10和20，求两个数的和
	int c = 10;
	int d = 20;
	printf("%d\n", c + d);
	int e = d + c;
	printf("%d\n",e);

	//练习2;用一个变量表示微信的余额
	// 需求：一开始微信的余额为100元，收到了一个2元的红包
	int money = 100;
	money = money + 2;
	printf("%d\n", money);
		return 0;
}