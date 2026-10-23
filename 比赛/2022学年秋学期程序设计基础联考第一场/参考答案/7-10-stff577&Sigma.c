#include <stdio.h>

/*
 * 画出大小为 n 的 Σ（n 为偶数）。总宽 3n、总高 2n-1：
 *   首行、末行：3n 个 '*'；
 *   中间各行：令 k = min(r, 2n-2-r)，
 *     左端 '*' 位于第 k 列；
 *     右端 '*' 位于第 3n-1-k 列，且只在 k <= n/2-1 时绘制。
 */
int main(void) {
    int n;
    scanf("%d", &n);

    int w = 3 * n;
    int rows = 2 * n - 1;
    int innerLimit = n / 2 - 1;

    for (int r = 0; r < rows; r++) {
        if (r == 0 || r == rows - 1) {
            for (int c = 0; c < w; c++) putchar('*');
            putchar('\n');
            continue;
        }

        int k = r < rows - 1 - r ? r : rows - 1 - r;

        for (int c = 0; c < w; c++) {
            int star = 0;
            if (c == k) star = 1;
            if (k <= innerLimit && c == w - 1 - k) star = 1;
            putchar(star ? '*' : ' ');
        }
        putchar('\n');
    }
    return 0;
}