#include <stdio.h>

/*
 * 给定 n-1 条父子边，构成一棵以根为起点的树。
 * 求 x 与 y 的辈分差：先算出各自到根的深度，
 * 再用 LCA 求实际间隔。数据规模 n <= 100，直接逐级向上标记即可。
 */
int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);

        int parent[105];
        for (int i = 0; i <= n; i++) parent[i] = 0;

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            parent[v] = u;
        }

        int x, y;
        scanf("%d %d", &x, &y);

        /* 计算深度 */
        int depX = 0, depY = 0;
        for (int v = x; v != 0; v = parent[v]) depX++;
        for (int v = y; v != 0; v = parent[v]) depY++;

        /* 对齐到同深度，再同时向上，求 LCA 的距离 */
        int ax = x, ay = y;
        int d = 0;
        while (depX > depY) { ax = parent[ax]; depX--; d++; }
        while (depY > depX) { ay = parent[ay]; depY--; d++; }
        while (ax != ay && ax != 0 && ay != 0) {
            ax = parent[ax];
            ay = parent[ay];
            d += 2;
        }

        printf("%d\n", d);
    }
    return 0;
}