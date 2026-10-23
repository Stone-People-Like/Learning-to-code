#include <stdio.h>

int main(void) {
    char color;
    long long a, b, c, d, e;
    scanf(" %c", &color);
    scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e);

    /* 只取个位参与乘法，避免溢出 */
    int prod = (int)((a % 10) * (b % 10) % 10);
    prod = (int)((long long)prod * (c % 10) % 10);
    prod = (int)((long long)prod * (d % 10) % 10);

    int like = (int)(e % 10);

    if (color == 'p' && prod == like)
        printf("hihihi,yaquyuebing,hihihi %d\n", prod);
    else
        printf("meidechi,555 %d\n", prod);
    return 0;
}