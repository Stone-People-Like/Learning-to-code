#include <stdio.h>

/*
 * 单个六边形占 4 行一圈（加上共享的顶边共 5 行）：
 *    +---+
 *   /     \
 *  +       +
 *   \     /
 * 相邻六边形上下共享一条 +---+ 边，因此 n 个共 4n+1 行。
 * 第 r 行内容只由 r % 4 决定。
 */
int main(void) {
    int n;
    scanf("%d", &n);

    for (int r = 0; r <= 4 * n; r++) {
        switch (r % 4) {
            case 0: printf("   +---+\n"); break;
            case 1: printf("  /     \\\n"); break;
            case 2: printf(" +       +\n"); break;
            default: printf("  \\     /\n"); break;
        }
    }
    return 0;
}