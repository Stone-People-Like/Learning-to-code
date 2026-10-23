#include <stdio.h>

/*
 * 用 11、111、1111、… 累加凑出 n（每个数可重复使用）。
 * gcd(11,111) = 1，由 Frobenius 定理，所有 n > 11*111 - 11 - 111 = 1099
 * 都能表示；因此 n > 1099 直接 YES，n <= 1099 用完全背包判定。
 */
#define LIM 1100

int main(void) {
    long long n;
    scanf("%lld", &n);

    if (n > 1099) {
        printf("YES\n");
        return 0;
    }

    long long reps[10];
    int cnt = 0;
    long long v = 1;   /* 从 11 开始，1 不在可用的数字里 */
    for (int d = 2; d <= 9; d++) {
        v = v * 10 + 1;
        if (v <= n) reps[cnt++] = v;
    }

    char dp[LIM] = {0};
    dp[0] = 1;
    for (int i = 0; i < cnt; i++)
        for (long long s = reps[i]; s <= n; s++)
            if (dp[s - reps[i]]) dp[s] = 1;

    printf("%s\n", dp[n] ? "YES" : "NO");
    return 0;
}