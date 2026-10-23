#include <stdio.h>

/* 斐波那契第 n 项能否被 3 整除，n <= 45，用 long long 直接算。 */
int main(void) {
    int n;
    scanf("%d", &n);

    long long a = 1, b = 1;
    if (n == 1 || n == 2) {
        printf("N\n");
        return 0;
    }
    for (int i = 3; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }
    printf("%c\n", b % 3 == 0 ? 'Y' : 'N');
    return 0;
}