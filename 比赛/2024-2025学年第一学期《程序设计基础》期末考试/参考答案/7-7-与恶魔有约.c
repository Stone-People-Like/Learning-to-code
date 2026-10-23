#include <stdio.h>
#include <string.h>

/* 按 (到期日期, 签订日期, 名字字典序) 三元组取最小。 */
typedef struct {
    char name[128];
    long long sign;
    long long dur;
    long long expire;
} Contract;

int main(void) {
    int n;
    scanf("%d", &n);

    Contract best;
    int has = 0;

    for (int i = 0; i < n; i++) {
        Contract c;
        scanf("%s %lld %lld", c.name, &c.sign, &c.dur);
        c.expire = c.sign + c.dur;

        if (!has) {
            best = c;
            has = 1;
            continue;
        }

        int better = 0;
        if (c.expire != best.expire)
            better = c.expire < best.expire;
        else if (c.sign != best.sign)
            better = c.sign < best.sign;
        else
            better = strcmp(c.name, best.name) < 0;

        if (better) best = c;
    }

    printf("%s\n", best.name);
    return 0;
}