#include <stdio.h>
#include <stdlib.h>

/*
 * 每步只能走 (x+1, y+1) 或 (x-2, y)。
 * 目标位移 dx = c - a，dy = d - b。
 * 设第一种走 u 步、第二种走 v 步：
 *   u = dy，且 dx = u - 2v = dy - 2v  =>  v = (dy - dx) / 2
 * 需要 u >= 0、v >= 0、dy - dx 为偶数。
 */
int main(void) {
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    long long dx = c - a;
    long long dy = d - b;

    if (dy < 0) {
        printf("-1\n");
        return 0;
    }

    long long diff = dy - dx;
    if (diff < 0 || diff % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    long long v = diff / 2;
    printf("%lld\n", dy + v);
    return 0;
}