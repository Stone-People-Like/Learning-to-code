#include <stdio.h>

/*
 * n 块圆盘移动次数为 2^n - 1 秒，换算成 日:时:分:秒。
 * n <= 30，2^30 约为 1.07e9 秒，用 long long 足够。
 */
int main(void) {
    int n;
    scanf("%d", &n);

    long long total = (1LL << n) - 1;

    long long days = total / 86400;
    total %= 86400;
    long long hours = total / 3600;
    total %= 3600;
    long long minutes = total / 60;
    long long seconds = total % 60;

    printf("%lld %lld %lld %lld\n", days, hours, minutes, seconds);
    return 0;
}