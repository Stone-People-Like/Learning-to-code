#include <stdio.h>

/*
 * 两个并排的 Σ（n 为偶数）。总宽 7n、总高 2n-1。
 *   首行、末行：第 0..3n-1 列与第 4n..7n-1 列为 '*'；
 *   中间各行令 k = min(r, 2n-2-r)：
 *     左 Σ 左端 '*' 在第 k 列，右端 '*' 在第 3n+k-1 列；
 *     右 Σ 右端 '*' 在第 7n-1-k 列，左端 '*' 在第 4n-k 列；
 *     两个内侧 '*' 只在 k <= n/2-1 时绘制。
 */
int main(void) {
    int n;
    scanf("%d", &n);

    int W = 7 * n;
    int rows = 2 * n - 1;
    int innerLimit = n / 2 - 1;

    char line[512];

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < W; c++) line[c] = ' ';

        if (r == 0 || r == rows - 1) {
            for (int c = 0; c < 3 * n; c++) line[c] = '*';
            for (int c = 4 * n; c < W; c++) line[c] = '*';
        } else {
            int k = r < rows - 1 - r ? r : rows - 1 - r;
            line[k] = '*';                    /* 左 Σ 左端 */
            line[W - 1 - k] = '*';            /* 右 Σ 右端 */
            if (k <= innerLimit) {
                line[3 * n + k - 1] = '*';    /* 左 Σ 内侧 */
                line[4 * n - k] = '*';        /* 右 Σ 内侧 */
            }
        }

        /* 去掉行尾多余空格后输出 */
        int end = W;
        while (end > 0 && line[end - 1] == ' ') end--;
        for (int c = 0; c < end; c++) putchar(line[c]);
        putchar('\n');
    }
    return 0;
}