#include <stdio.h>
#include <stdlib.h>

/* 对每个空地统计曼哈顿距离 <= k 的地雷数；地雷输出 -1。 */
int main(void) {
    int row, col, k;
    scanf("%d %d %d", &row, &col, &k);

    static char g[15][15];
    for (int i = 0; i < row; i++) scanf("%s", g[i]);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int ans;
            if (g[i][j] == '*') {
                ans = -1;
            } else {
                ans = 0;
                for (int r = 0; r < row; r++)
                    for (int c = 0; c < col; c++)
                        if (g[r][c] == '*' && abs(r - i) + abs(c - j) <= k)
                            ans++;
            }
            if (j) putchar(' ');
            printf("%d", ans);
        }
        putchar('\n');
    }
    return 0;
}