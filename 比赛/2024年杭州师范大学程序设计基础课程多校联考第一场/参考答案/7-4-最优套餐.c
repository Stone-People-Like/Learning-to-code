#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    long long best = -1;
    for (int i = 0; i < n; i++) {
        long long p;
        scanf("%lld", &p);
        if (best < 0 || p < best) best = p;
    }
    printf("%lld\n", best);
    return 0;
}