#include <stdio.h>

/*
 * n 个首尾相连的字母 v：高 3 行、总宽 4n+1。
 * 第 0 行：列 4i（i = 0..n）处为 '*'；
 * 第 1 行：列 4i+1 与 4i+3（i = 0..n-1）处为 '*'；
 * 第 2 行：列 4i+2（i = 0..n-1）处为 '*'。
 * 行尾多余空格需去掉。
 */
int main(void) {
    int n;
    scanf("%d", &n);

    int W = 4 * n + 1;
    char line[1024];

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < W; c++) line[c] = ' ';

        if (r == 0) {
            for (int i = 0; i <= n; i++) line[4 * i] = '*';
        } else if (r == 1) {
            for (int i = 0; i < n; i++) {
                line[4 * i + 1] = '*';
                line[4 * i + 3] = '*';
            }
        } else {
            for (int i = 0; i < n; i++) line[4 * i + 2] = '*';
        }

        int end = W;
        while (end > 0 && line[end - 1] == ' ') end--;
        for (int c = 0; c < end; c++) putchar(line[c]);
        putchar('\n');
    }
    return 0;
}