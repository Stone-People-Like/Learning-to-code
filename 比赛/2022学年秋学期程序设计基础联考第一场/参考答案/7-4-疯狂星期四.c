#include <stdio.h>

/*
 * 四张代金券里任取三张（可叠加），取金额最大的三张即可获得最大购买力：
 *   可支付 = (三张最大面额之和) * k
 * 依次判断能否买 A、B、C，否则 POOR。
 */
int main(void) {
    long long x, y, z;
    scanf("%lld %lld %lld", &x, &y, &z);

    long long v[4];
    for (int i = 0; i < 4; i++) scanf("%lld", &v[i]);

    long long k;
    scanf("%lld", &k);

    /* 选出最大的三张 */
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (v[j] > v[i]) {
                long long t = v[i];
                v[i] = v[j];
                v[j] = t;
            }

    long long money = (v[0] + v[1] + v[2]) * k;

    if (money >= x)
        printf("A\n");
    else if (money >= y)
        printf("B\n");
    else if (money >= z)
        printf("C\n");
    else
        printf("POOR\n");
    return 0;
}