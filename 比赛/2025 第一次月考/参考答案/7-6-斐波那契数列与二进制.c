#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    long long a = 1, b = 1;
    if (n == 1 || n == 2) b = 1;
    for (int i = 3; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }
    long long v = (n == 1) ? 1 : b;

    int zero = 0;
    while (v > 0) {
        if (v % 2 == 0) zero++;
        v /= 2;
    }
    printf("%d\n", zero);
    return 0;
}