#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b)
        printf("A\n");
    else if (a < b)
        printf("B\n");
    else
        printf("=\n");
    return 0;
}