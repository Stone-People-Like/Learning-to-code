#include <stdio.h>

/*
 * a 张 1 元、b 张 2 元，最大可支付 a + 2b。
 * 若 a == 0，则只能表示偶数，答案 1；
 * 否则 1..a+2b 全部可表示，答案 a + 2b + 1。
 */
int main(void) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    if (a == 0)
        printf("1\n");
    else
        printf("%lld\n", a + 2 * b + 1);
    return 0;
}