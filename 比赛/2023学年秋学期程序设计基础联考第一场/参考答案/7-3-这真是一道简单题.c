#include <stdio.h>

/*
 * n <= 1        : 0 元
 * 1 < n <= 5    : 8 * n
 * n > 5         : 前 5 小时 40 元，第 k 小时（k>=6）收 8 + (k-5) 元
 * 封顶 300 元。
 */
int main(void) {
    int n;
    scanf("%d", &n);

    long long fee = 0;
    if (n <= 1) {
        fee = 0;
    } else if (n <= 5) {
        fee = 8LL * n;
    } else {
        fee = 40;
        for (int k = 6; k <= n; k++) fee += 8 + (k - 5);
    }

    if (fee > 300) fee = 300;
    printf("%lld\n", fee);
    return 0;
}