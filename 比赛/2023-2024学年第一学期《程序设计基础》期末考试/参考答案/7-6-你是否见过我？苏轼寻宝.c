#include <stdio.h>

/*
 * 宝物所在点：在同一行中水深最小（东西最浅），
 * 在同一列中水深最大（南北最深）。
 */
int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    static int a[105][105];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int rowMin = 1, colMax = 1;
            for (int k = 0; k < m; k++)
                if (a[i][k] < a[i][j]) rowMin = 0;
            for (int k = 0; k < n; k++)
                if (a[k][j] > a[i][j]) colMax = 0;

            if (rowMin && colMax) {
                printf("(%d,%d)\n", i + 1, j + 1);
                return 0;
            }
        }
    }
    return 0;
}