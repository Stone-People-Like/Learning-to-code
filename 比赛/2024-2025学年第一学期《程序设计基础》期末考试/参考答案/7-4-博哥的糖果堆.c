#include <stdio.h>
#include <stdlib.h>

/* 对区间 [i,j] 做非降 / 非升排序。数据规模小，直接每次排序即可。 */
static int cmpAsc(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}
static int cmpDesc(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x < y) - (x > y);
}

int main(void) {
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int t;
    scanf("%d", &t);
    while (t--) {
        int k, i, j;
        scanf("%d %d %d", &k, &i, &j);
        int len = j - i + 1;
        if (k == 1)
            qsort(a + i - 1, len, sizeof(int), cmpAsc);
        else
            qsort(a + i - 1, len, sizeof(int), cmpDesc);
    }

    for (int i = 0; i < n; i++) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    }
    putchar('\n');
    free(a);
    return 0;
}