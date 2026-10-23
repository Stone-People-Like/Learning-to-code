#include <stdio.h>

int main(void) {
    long long a, b;
    char op;
    scanf("%lld %lld %c", &a, &b, &op);

    switch (op) {
        case '+': printf("%lld\n", a + b); break;
        case '-': printf("%lld\n", a - b); break;
        case '*': printf("%lld\n", a * b); break;
        case '/':
            if (b == 0)
                printf("NaN\n");
            else
                printf("%lld\n", a / b);
            break;
        default: break;
    }
    return 0;
}