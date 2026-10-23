#include <stdio.h>

/*
 * 枚举 a < b < c，a + b + c = n 且 a^2 + b^2 = c^2。
 * 统计满足条件的三元组个数；0 个输出 No Joyfine，1 个输出 a*b*c，多个输出 Many + 个数。
 */
int main(void) {
    long long n;
    scanf("%lld", &n);

    long long cnt = 0, prod = 0;
    for (long long a = 1; a * 3 < n; a++) {
        for (long long b = a + 1; a + b * 2 < n; b++) {
            long long c = n - a - b;
            if (c <= b) break;
            if (a * a + b * b == c * c) {
                cnt++;
                prod = a * b * c;
            }
        }
    }

    if (cnt == 0)
        printf("No Joyfine\n");
    else if (cnt == 1)
        printf("%lld\n", prod);
    else
        printf("Many %lld\n", cnt);
    return 0;
}