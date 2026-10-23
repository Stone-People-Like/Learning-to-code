#include <stdio.h>

/* 3n+1 迭代（冰雹序列），统计到变为 1 所需的步数。 */
int main(void) {
    long long x;
    scanf("%lld", &x);

    int steps = 0;
    while (x != 1) {
        if (x % 2 == 0)
            x /= 2;
        else
            x = x * 3 + 1;
        steps++;
    }
    printf("%d\n", steps);
    return 0;
}