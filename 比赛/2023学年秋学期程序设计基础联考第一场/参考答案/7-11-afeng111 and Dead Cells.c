#include <stdio.h>

/*
 * 每回合枭首者先手，只能二选一：攻击 x 或回血 d（不超过最大血量）。
 * 收藏家随后造成 y 伤害。血量 <= 0 立即死亡。
 *
 * 最优策略：血量扛不住下一击（hp - y <= 0）且还有血瓶时回血，否则攻击。
 * 回血后若仍扛不住下一击，则必败。
 * 回合数 = 击杀所需攻击次数 + 回血次数，最多 cnt 次回血，直接模拟即可。
 */
int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long hpa, hpb, x, y, d, cnt;
        scanf("%lld %lld %lld %lld %lld %lld", &hpa, &hpb, &x, &y, &d, &cnt);

        long long hp = hpa, bossHp = hpb;
        int win = 0;

        /* 上限：击杀所需回合数 + 全部血瓶数 + 余量 */
        long long maxTurns = (hpb + x - 1) / x + cnt + 5;

        for (long long turn = 0; turn < maxTurns; turn++) {
            /* --- 枭首者回合：能一击击杀就攻击，优先结束战斗 --- */
            if (bossHp - x <= 0) {
                win = 1;
                break;
            }

            if (hp - y <= 0) {
                /* 扛不住下一击：有血瓶就回血，否则必败 */
                if (cnt == 0) break;
                hp += d;
                if (hp > hpa) hp = hpa;
                cnt--;
                /* 回血后仍扛不住，说明再补也无意义 */
                if (hp - y <= 0) {
                    while (cnt > 0 && hp - y <= 0) {
                        hp += d;
                        if (hp > hpa) hp = hpa;
                        cnt--;
                    }
                    if (hp - y <= 0) break;
                }
            } else {
                bossHp -= x;
            }

            /* --- 收藏家回合 --- */
            hp -= y;
            if (hp <= 0) break;
        }

        printf("%c\n", win ? 'Y' : 'N');
    }
    return 0;
}