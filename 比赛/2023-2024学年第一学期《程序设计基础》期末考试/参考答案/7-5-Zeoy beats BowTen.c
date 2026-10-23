#include <stdio.h>
#include <stdlib.h>

/* 按实力从弱到强输出分身编号（实力互不相同）。 */
typedef struct {
    int power;
    int idx;
} Node;

static int cmp(const void *a, const void *b) {
    int p1 = ((const Node *)a)->power;
    int p2 = ((const Node *)b)->power;
    return (p1 > p2) - (p1 < p2);
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        Node *a = (Node *)malloc(sizeof(Node) * n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i].power);
            a[i].idx = i + 1;
        }

        qsort(a, n, sizeof(Node), cmp);

        for (int i = 0; i < n; i++) {
            if (i) putchar(' ');
            printf("%d", a[i].idx);
        }
        putchar('\n');
        free(a);
    }
    return 0;
}