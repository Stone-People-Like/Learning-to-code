//
// Created by admin on 2026/10/22.
//
#include <stdio.h>
#include <float.h>

int main() {
    /* ========== 一、浮点类型的定义方法 ========== */
    // 基本格式和整数一样：类型说明符 变量名 = 初值;
    // 关键在字面量的后缀：不带后缀的小数默认就是 double
    float       f  = 3.14f;   // 4 字节，后缀 f 或 F
    double      d  = 3.14;    // 8 字节，默认类型，不用加后缀
    long double ld = 3.14L;   // 后缀 l 或 L，宽度随平台变

    // 科学计数法：1.5e3 就是 1500.0，e 后面是指数
    double sci = 1.5e3;
    // 也可以写成小数形式，两种写法完全等价
    double dec = 1500.0;

    printf("f=%.2f  d=%.2f  ld=%.2Lf\n", f, d, ld);
    printf("sci=%.1f  dec=%.1f\n", sci, dec);

    /* ========== 二、用 sizeof 测量本机的大小 ========== */
    // 和整数一样，返回 size_t，格式符用 %zu
    printf("\n---- sizeof 测类型（字节）----\n");
    printf("sizeof(float)       = %zu\n", sizeof(float));
    printf("sizeof(double)      = %zu\n", sizeof(double));
    printf("sizeof(long double) = %zu\n", sizeof(long double));

    /* ========== 三、精度与范围 ========== */
    // float.h 里的 FLT_DIG / DBL_DIG / LDBL_DIG 是「保证能精确表示的十进制位数」
    printf("\n---- 有效数字位数（float.h）----\n");
    printf("float       : %d 位\n", FLT_DIG);
    printf("double      : %d 位\n", DBL_DIG);
    printf("long double : %d 位\n", LDBL_DIG);

    printf("\n---- 能表示的最大值（float.h）----\n");
    printf("float       : %e\n", FLT_MAX);
    printf("double      : %e\n", DBL_MAX);
    printf("long double : %Le\n", LDBL_MAX);

    /* ========== 四、精度丢失的经典例子 ========== */
    // 二进制无法精确表示 0.1、0.2 这类十进制小数，只能存近似值
    printf("\n---- 精度问题 ----\n");
    printf("0.1 + 0.2   = %.20f\n", 0.1 + 0.2);
    printf("0.1 + 0.2 == 0.3 ? %s\n", (0.1 + 0.2 == 0.3) ? "真" : "假");

    // 位数越多，误差越小
    float  third_f = 1.0f / 3.0f;
    double third_d = 1.0 / 3.0;
    printf("float  1/3  = %.20f\n", third_f);
    printf("double 1/3  = %.20f\n", third_d);

    // 正确做法：判断两个浮点数的差值是否足够小，而不是直接比 ==
    double a = 0.1 + 0.2;
    double b = 0.3;
    double diff = a - b;
    if (diff < 0) {
        diff = -diff;
    }
    printf("用误差比较 : %s\n", (diff < 1e-9) ? "相等" : "不相等");

    /* ========== 五、整数除法 vs 浮点除法 ========== */
    // 两个整数相除，结果是整数，小数部分直接截断
    printf("\n---- 除法 ----\n");
    printf("5 / 2       = %d\n", 5 / 2);
    printf("5 / 2.0     = %.1f\n", 5 / 2.0);   // 有一边是浮点，结果就是浮点
    printf("5.0f / 2    = %.1f\n", 5.0f / 2);

    return 0;
}