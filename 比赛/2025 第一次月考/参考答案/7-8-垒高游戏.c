#include <stdio.h>

/*
 * n 步操作，每步净变化 -1 或 +1，且高度不能为负。
 * m 可达当且仅当 m <= n 且 m 与 n 同奇偶。
 */
int main(void) {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    if (m <= n && (n - m) % 2 == 0)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}