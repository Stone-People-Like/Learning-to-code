#include <stdio.h>

/*
 * 逐小时模拟。状态量：
 *   spirit  精神状态
 *   prog    DDL 进度（封顶 100）
 *   hiBuff  剩余「高效」小时数（睡觉后 3 小时，含唤醒当小时共 4 个学习小时）
 *   loBuff  剩余「低效」小时数（玩游戏后 2 小时）
 *   forced  强制睡眠剩余小时数（精神降到 0 及以下时触发，至少 2 小时）
 *
 * 规则说明（依样例反推）：
 *   - 睡觉：精神 +6，进入高效状态；
 *   - 学习：精神 -7，进度 +floor(7 × 倍率)；倍率为 1.5（高效）、0.5（低效）、1.0（正常）；
 *           高效与低效同时存在时取低效（保守）；
 *   - 玩游戏：精神 -13，进入 2 小时低效；
 *   - 强制睡眠期间忽略原本的动作，每小时精神 +6，直到恢复为正数。
 */
int main(void) {
    int n;
    long long spirit;
    scanf("%d %lld", &n, &spirit);

    char act[128];
    scanf("%s", act);

    int prog = 0;
    int hiBuff = 0;
    int loBuff = 0;
    int forced = 0;

    for (int h = 0; h < n; h++) {
        char a = act[h];

        /* 强制睡眠：任何动作都被忽略，只睡觉 */
        if (forced > 0) {
            forced--;
            spirit += 6;
            hiBuff = 4;          /* 唤醒后进入高效状态 */
            continue;
        }

        switch (a) {
            case 'S':
                spirit += 6;
                hiBuff = 4;
                break;

            case 'L': {
                if (prog < 100) {
                    double mult = 1.0;
                    if (hiBuff > 0 && loBuff > 0)
                        mult = 0.5;          /* 两者并存取低效 */
                    else if (hiBuff > 0)
                        mult = 1.5;
                    else if (loBuff > 0)
                        mult = 0.5;

                    int inc = (int)(7.0 * mult);
                    prog += inc;
                    if (prog > 100) prog = 100;
                    spirit -= 7;
                } else {
                    spirit += 3;             /* DDL 已完成则学习回精神 */
                }
                break;
            }

            case 'P':
                spirit -= 13;
                loBuff = 2;
                break;

            default:
                break;
        }

        if (hiBuff > 0) hiBuff--;
        if (loBuff > 0) loBuff--;

        /* 精神降到 0 及以下：强制睡眠至少 2 小时 */
        if (spirit <= 0 && h < n - 1)
            forced = 2;
    }

    printf("%d %lld\n", prog, spirit);
    printf("%s\n", prog >= 100 ? "The game of life" : "Life is not just about games");
    return 0;
}