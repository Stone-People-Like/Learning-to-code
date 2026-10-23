#include <stdio.h>

/* 时间限制应为正解耗时的两倍：T2 == 2 * T1 视为合理。 */
int main(void) {
    long long t1, t2;
    scanf("%lld %lld", &t1, &t2);
    printf("%s\n", (t2 == 2 * t1) ? "AC" : "RE");
    return 0;
}