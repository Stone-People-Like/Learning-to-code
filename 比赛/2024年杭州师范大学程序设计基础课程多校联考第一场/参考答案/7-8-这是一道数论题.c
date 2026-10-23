#include <stdio.h>

static int isPrime(int v) {
    if (v < 2) return 0;
    for (int d = 2; d * d <= v; d++)
        if (v % d == 0) return 0;
    return 1;
}

static long long gcd(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int hasPrime = 0;
    long long g = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (isPrime(x)) hasPrime = 1;
        g = gcd(g, x);
    }

    if (hasPrime)
        printf("QAQ\n");
    else
        printf("%lld\n", g);
    return 0;
}