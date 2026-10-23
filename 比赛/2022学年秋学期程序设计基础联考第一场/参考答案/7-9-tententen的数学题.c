#include <stdio.h>

/*
 * 要求 a+b、b+c、a+c 都是 k 的倍数。
 * 由 (a+b) ≡ 0、(a+c) ≡ 0 得 b ≡ c ≡ -a，再代入 b+c ≡ 0 得 2a ≡ 0 (mod k)。
 * 即 a ≡ b ≡ c (mod k)，且 2a ≡ 0 (mod k)。
 * 记 cnt[r] = [1,n] 中模 k 余 r 的个数，枚举 a 的余数 r（满足 2r % k == 0），
 * 累加 cnt[r]^3 即可。
 */
int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    long long cnt[105] = {0};
    for (int v = 1; v <= n; v++) cnt[v % k]++;

    long long ans = 0;
    for (int r = 0; r < k; r++) {
        if ((2 * r) % k == 0) ans += cnt[r] * cnt[r] * cnt[r];
    }
    printf("%lld\n", ans);
    return 0;
}