#include <stdio.h>

static double a3, a2, a1, a0;

static double f(double x) {
    return ((a3 * x + a2) * x + a1) * x + a0;
}

/* 二分法求三次方程在 [a,b] 内的根，阈值 0.001 */
int main(void) {
    scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
    double a, b;
    scanf("%lf %lf", &a, &b);

    while (b - a >= 0.001) {
        double mid = (a + b) / 2.0;
        double fm = f(mid);
        if (fm == 0.0) {
            a = b = mid;
            break;
        }
        if (f(a) * fm < 0)
            b = mid;
        else
            a = mid;
    }
    printf("%.2f\n", (a + b) / 2.0);
    return 0;
}