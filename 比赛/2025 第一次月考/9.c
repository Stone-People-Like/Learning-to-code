#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // 大于等于 1110 时一定可以表示
    if (n >= 1110) {
        printf("YES");
        return 0;
    }

    // 小范围直接枚举用了多少个 111
    for (int b = 0; b * 111 <= n; b++) {
        int rest = n - b * 111;
        if (rest % 11 == 0) {
            printf("YES");
            return 0;
        }
    }

    printf("NO");
    return 0;
}