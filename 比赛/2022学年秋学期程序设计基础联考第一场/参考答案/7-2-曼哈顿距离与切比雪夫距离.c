#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x1, y1, x2, y2;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);

    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    int manhattan = dx + dy;
    int chebyshev = dx > dy ? dx : dy;

    printf("%d %d\n", manhattan, chebyshev);
    return 0;
}