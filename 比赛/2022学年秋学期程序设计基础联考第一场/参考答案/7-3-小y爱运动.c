#include <stdio.h>

/* 三个时间段总分钟数 = Σ (结束时刻 - 开始时刻)，判断是否 >= 240 分钟。 */
int main(void) {
    int total = 0;
    for (int i = 0; i < 3; i++) {
        int h1, m1, h2, m2;
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        total += (h2 * 60 + m2) - (h1 * 60 + m1);
    }
    printf("%d %d\n", total / 60, total % 60);
    printf("%s\n", total >= 240 ? "YES" : "NO");
    return 0;
}