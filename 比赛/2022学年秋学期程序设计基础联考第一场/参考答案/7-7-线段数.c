#include <stdio.h>

/*
 * a_i = 1 / (i * (2i - 1))，序列单调递减。
 * 找满足 a_i > eps >= a_{i+1} 的 i，输出前 i+1 项之和。
 */
int main(void) {
    double eps;
    scanf("%lf", &eps);

    int i = 1;
    while (1) {
        double ai = 1.0 / ((double)i * (2.0 * i - 1.0));
        double anext = 1.0 / ((double)(i + 1) * (2.0 * (i + 1) - 1.0));
        if (ai > eps && anext <= eps) break;
        i++;
    }

    double sum = 0.0;
    for (int k = 1; k <= i + 1; k++)
        sum += 1.0 / ((double)k * (2.0 * k - 1.0));

    printf("%.6f\n", sum);
    return 0;
}