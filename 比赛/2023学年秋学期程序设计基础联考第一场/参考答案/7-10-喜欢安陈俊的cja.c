#include <stdio.h>

/*
 * 老师走到第 pos 位同学身后需要 (pos-1) * t 分钟（小安在第 q 分钟到达）。
 * 到那时：
 *   正常同学已 AC 题数 = elapsed / x
 *   小安已 AC 题数     = (elapsed - q) / y
 * 比较两者判断 Yes / So So / No；若老师到达时小安还没到（elapsed < q）则 No。
 */
int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long x, y, q, pos, t;
        scanf("%lld %lld %lld %lld %lld", &x, &y, &q, &pos, &t);

        long long arrive = (pos - 1) * t;   /* 老师来到小安身后的时刻 */

        if (arrive < q) {
            printf("No\n");
            continue;
        }

        long long normal = arrive / x;          /* 正常进度 */
        long long mine = (arrive - q) / y;      /* 小安进度 */

        if (mine > normal)
            printf("Yes\n");
        else if (mine == normal)
            printf("So So\n");
        else
            printf("No\n");
    }
    return 0;
}