#include <stdio.h>

int main(void) {
    long long B, H, X;
    scanf("%lld %lld %lld", &B, &H, &X);

    if (B > H)
        printf("BE\n");
    else if (B < H)
        printf("HE\n");
    else
        printf("%s\n", X >= 10 ? "BE" : "HE");
    return 0;
}