#include <stdio.h>

/*
 * 三个矩形可各自旋转 90°，按 3! × 2^3 = 48 种摆法枚举，
 * 每种摆法考虑「三块并排 / 一块叠在另两块之上 / 两块叠在一侧」等
 * 有限的最优拼法，取外接矩形面积最小者。
 * 矩形数只有 3 个，直接全排列 + 全旋转 + 全切分布局搜索即可。
 */

static long long best;

static long long maxll(long long a, long long b) { return a > b ? a : b; }
static long long minll(long long a, long long b) { return a < b ? a : b; }

static void tryLayout(const long long r[3][2]) {
    long long w0 = r[0][0], h0 = r[0][1];
    long long w1 = r[1][0], h1 = r[1][1];
    long long w2 = r[2][0], h2 = r[2][1];

    /* 1) 三块横向并排 */
    long long w = w0 + w1 + w2, h = maxll(h0, maxll(h1, h2));
    best = minll(best, w * h);

    /* 2) 三块纵向堆叠 */
    w = maxll(w0, maxll(w1, w2));
    h = h0 + h1 + h2;
    best = minll(best, w * h);

    /* 3) 两块先并排成一块，再与第三块横拼或竖拼 */
    long long bw = w1 + w2, bh = maxll(h1, h2);
    /* 3a) 横拼：宽度相加 */
    best = minll(best, (bw + w0) * maxll(bh, h0));
    /* 3b) 竖拼：高度相加 */
    best = minll(best, maxll(bw, w0) * (bh + h0));

    /* 4) 两块先纵向叠成一块，再与第三块横拼或竖拼 */
    bw = maxll(w1, w2);
    bh = h1 + h2;
    best = minll(best, (bw + w0) * maxll(bh, h0));
    best = minll(best, maxll(bw, w0) * (bh + h0));
}

static void permute(long long r[3][2], int k) {
    if (k == 3) {
        /* 每块矩形均可旋转 */
        for (int m = 0; m < 8; m++) {
            long long t[3][2];
            for (int i = 0; i < 3; i++) {
                if (m & (1 << i)) { t[i][0] = r[i][1]; t[i][1] = r[i][0]; }
                else              { t[i][0] = r[i][0]; t[i][1] = r[i][1]; }
            }
            tryLayout(t);
        }
        return;
    }
    for (int i = k; i < 3; i++) {
        long long a = r[k][0], b = r[k][1];
        r[k][0] = r[i][0]; r[k][1] = r[i][1];
        r[i][0] = a;       r[i][1] = b;
        permute(r, k + 1);
        a = r[k][0]; b = r[k][1];
        r[k][0] = r[i][0]; r[k][1] = r[i][1];
        r[i][0] = a;       r[i][1] = b;
    }
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long r[3][2];
        for (int i = 0; i < 3; i++) scanf("%lld %lld", &r[i][0], &r[i][1]);
        best = 1LL << 62;
        permute(r, 0);
        printf("%lld\n", best);
    }
    return 0;
}