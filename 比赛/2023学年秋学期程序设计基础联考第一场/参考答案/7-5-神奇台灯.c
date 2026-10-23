#include <stdio.h>

/* 亮度在 0..a 之间循环，周期为 a+1，按 m 次后亮度为 m % (a+1)。 */
int main(void) {
    long long a, m;
    scanf("%lld %lld", &a, &m);
    printf("%lld\n", m % (a + 1));
    return 0;
}