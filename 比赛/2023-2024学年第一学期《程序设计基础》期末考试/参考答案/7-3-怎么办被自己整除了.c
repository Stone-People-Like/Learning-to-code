#include <stdio.h>

/* 统计 a[i] 能被下标 i（从 1 开始）整除的个数。 */
int main(void) {
    int n;
    scanf("%d", &n);

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        long long v;
        scanf("%lld", &v);
        if (v % i == 0) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}