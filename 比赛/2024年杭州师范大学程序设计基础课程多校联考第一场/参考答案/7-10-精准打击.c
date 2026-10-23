#include <stdio.h>

/*
 * 矩形 [0,n] x [0,m]，激光从 (x,0) 以 45° 向上射出。
 * 位置可用 (X, Y) 表示，其中 X = x + t、Y = t（t 为时间），
 * 碰到边界按镜面反射折算回区间 [0, n] / [0, m] 内。
 * 展开法：把运动轨迹看成在无限平面中沿直线 x+t, t 前进，
 * 每撞一次边界计一次反弹。命中 (0,0) 的条件是
 *   X ≡ 0 (mod 2n) 且 Y ≡ 0 (mod 2m)。
 * 直接模拟直到状态重复。
 */
int main(void) {
    long long n, m, x;
    scanf("%lld %lld %lld", &n, &m, &x);

    /* 方向 dx, dy ∈ {+1,-1}，位置用未折叠坐标 px, py 表示 */
    long long px = x, py = 0;
    long long dx = 1, dy = 1;
    long long bounces = 0;

    /* 状态空间有限，最多 2n * 2m 个状态 */
    long long limit = 4 * n * m + 10;
    for (long long step = 0; step < limit; step++) {
        /* 走到下一个边界 */
        long long tx, ty;
        if (dx > 0) tx = n - px; else tx = px;
        if (dy > 0) ty = m - py; else ty = py;

        long long t = tx < ty ? tx : ty;
        px += dx * t;
        py += dy * t;

        if (px == 0 && py == 0) {
            printf("%lld\n", bounces);
            return 0;
        }

        if (tx == t && ty == t) {
            /* 同时撞两个边界（角落）：两个方向都掉头 */
            dx = -dx;
            dy = -dy;
            bounces++;
        } else if (tx == t) {
            dx = -dx;
            bounces++;
        } else {
            dy = -dy;
            bounces++;
        }
    }

    printf("Xunwuqishi is a vegetable dog.\n");
    return 0;
}