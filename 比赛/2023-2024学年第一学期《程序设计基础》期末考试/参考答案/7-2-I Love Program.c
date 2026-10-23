#include <stdio.h>

int main(void) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a == 1 && c == 1)
        printf("I can't help you\n");
    else if (d == 1)
        printf("Please be honest\n");
    else if (a == 0 && b == 0)
        printf("See you next time\n");
    else
        printf("You're amazing!\n");
    return 0;
}