#include <stdio.h>

/*
 * 两人需要两个座位。空座位数 = n - m。
 * 若已空出至少 2 个座位，立即入座，20 分钟后两碗都做好 → 20。
 * 否则需要等第 (m - n + 2) 位客人吃完（座位空出两个的那一时刻），
 * 时间为该客人剩余时间，再加 20 分钟。
 * 两人各自点餐，取最晚完成时间即可。
 */
int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[1005];
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);

    /* 升序排序，先吃完的腾出座位 */
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            if (a[j] < a[i]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }

    int free_seats = n - m;
    if (free_seats >= 2) {
        printf("20\n");
        return 0;
    }

    /* 需要等 (2 - free_seats) 位客人离场 */
    int need = 2 - free_seats;
    printf("%d\n", a[need - 1] + 20);
    return 0;
}