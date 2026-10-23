#include <stdio.h>
#include <math.h>

/*
 * 设两人在 x 处分界：小佳负责修 [0,x]，小慧负责修 [x,n]。
 * 某人从起点 p 出发覆盖区间 [l,r] 的最短行程 =
 *     min(|p-l|, |p-r|) + (r-l)
 * 所需时间即行程 / 速度。答案 = min over x of max(两人的时间)。
 * 该函数关于 x 为凸函数，用三分法求最小值（x 允许取 0 或 n，
 * 即一人包揽全程）。
 */
static double cost(double p, double v, double l, double r) {
    /* 区间为空表示这段不用修，无需移动 */
    if (r - l <= 1e-12) return 0.0;
    double d1 = fabs(p - l), d2 = fabs(p - r);
    double start = d1 < d2 ? d1 : d2;
    return (start + (r - l)) / v;
}

/* 给定「谁负责左段 [0,x]、谁负责右段 [x,n]」，三分求最优分界点。 */
static double solveAssignment(double n, double pL, double vL, double pR, double vR) {
    double lo = 0.0, hi = n;
    for (int it = 0; it < 300; it++) {
        double m1 = lo + (hi - lo) / 3.0;
        double m2 = hi - (hi - lo) / 3.0;

        double f1a = cost(pL, vL, 0.0, m1), f1b = cost(pR, vR, m1, n);
        double f1 = f1a > f1b ? f1a : f1b;
        double f2a = cost(pL, vL, 0.0, m2), f2b = cost(pR, vR, m2, n);
        double f2 = f2a > f2b ? f2a : f2b;

        if (f1 < f2) hi = m2;
        else lo = m1;
    }

    /* 三分法找到的内部最优点，再与端点（一人包揽全程）比较 */
    double best = 1e18;
    double cand[3] = {lo, (lo + hi) / 2.0, hi};
    for (int i = 0; i < 3; i++) {
        double x = cand[i];
        if (x < 0) x = 0;
        if (x > n) x = n;
        double a = cost(pL, vL, 0.0, x), b = cost(pR, vR, x, n);
        double v = a > b ? a : b;
        if (v < best) best = v;
    }
    return best;
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        double n, J, vj, H, vh;
        scanf("%lf %lf %lf %lf %lf", &n, &J, &vj, &H, &vh);

        /* 两种分工：佳负责左段 / 慧负责左段；也涵盖一人包揽全程（x=0 或 n） */
        double a1 = solveAssignment(n, J, vj, H, vh);
        double a2 = solveAssignment(n, H, vh, J, vj);
        printf("%.5f\n", a1 < a2 ? a1 : a2);
    }
    return 0;
}