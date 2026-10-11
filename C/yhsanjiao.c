#include <stdio.h>

int main() {
    int a[12][12] = {0};
    int n, i, j;

    printf("n的值为：");
    scanf("%d", &n);

    if (n < 1 || n > 12) {
        printf("n 必须在 1 到 12 之间\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        a[i][0] = 1;
        a[i][i] = 1;
    }

    for (i = 0; i < n; i++) {
        for (j = 1; j < i; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }

    printf("杨辉三角为：\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}