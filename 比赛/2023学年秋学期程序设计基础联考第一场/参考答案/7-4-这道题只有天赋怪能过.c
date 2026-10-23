#include <stdio.h>

int main(void) {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    if (a + b + c < 1000 && a % 12 == 0 && a - b > b - c)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}