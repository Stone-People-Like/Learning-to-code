#include <stdio.h>
#include <stdlib.h>

/*
 * 按距离从左到右经过地标，累加记忆度；
 * 同一距离的地标需全部累加后再判断。
 * n 可达 1e18，只关心地标位置，把地标按距离排序即可。
 */
typedef struct {
    long long d;
    long long a;
} Landmark;

static int cmp(const void *x, const void *y) {
    long long d1 = ((const Landmark *)x)->d;
    long long d2 = ((const Landmark *)y)->d;
    return (d1 > d2) - (d1 < d2);
}

int main(void) {
    long long n, k, s, x;
    scanf("%lld %lld %lld %lld", &n, &k, &s, &x);

    Landmark *lm = (Landmark *)malloc(sizeof(Landmark) * k);
    for (long long i = 0; i < k; i++) scanf("%lld %lld", &lm[i].d, &lm[i].a);

    qsort(lm, k, sizeof(Landmark), cmp);

    long long cur = s;
    long long i = 0;
    while (i < k) {
        long long d = lm[i].d;
        /* 累加同一位置的所有地标 */
        while (i < k && lm[i].d == d) {
            cur += lm[i].a;
            i++;
        }
        if (cur >= x) {
            printf("%lld\n", d);
            free(lm);
            return 0;
        }
    }

    printf("I will stay with you\n");
    free(lm);
    return 0;
}