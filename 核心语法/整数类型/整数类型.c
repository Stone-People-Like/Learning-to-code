//
// Created by admin on 2026/10/22.
//
#include <stdio.h>
#include <limits.h>

int main() {
    /* ========== 一、整数类型的定义方法 ========== */
    // 基本格式：类型说明符 变量名 = 初值;
    // 初始化是好习惯：局部变量不初始化，值是内存里的随机垃圾
    char      c  = 'A';      // 1 字节，字符型，本质也是整数
    short     s  = 100;      // 短整型
    int       i  = 1000;     // 整型，日常最常用
    long      l  = 1000L;    // 长整型，后缀 L
    long long ll = 1000LL;   // 更长的整型，后缀 LL

    // 符号修饰符：signed 可省略（默认就是有符号），unsigned 表示非负数
    signed int   si = -100;
    unsigned int ui = 100U;  // 后缀 U
    unsigned char uc = 255;  // 无符号 char 最大就是 255

    // 先定义后赋值，也完全合法
    int later;
    later = 42;

    printf("c=%c  s=%d  i=%d  l=%ld  ll=%lld\n", c, s, i, l, ll);
    printf("si=%d  ui=%u  uc=%u  later=%d\n", si, ui, uc, later);

    /* ========== 二、用 sizeof 测量本机的数据类型大小 ========== */
    // sizeof 是运算符不是函数；返回类型是 size_t，格式符用 %zu
    printf("\n---- sizeof 测类型（字节）----\n");
    printf("sizeof(char)      = %zu\n", sizeof(char));
    printf("sizeof(short)     = %zu\n", sizeof(short));
    printf("sizeof(int)       = %zu\n", sizeof(int));
    printf("sizeof(long)      = %zu\n", sizeof(long));
    printf("sizeof(long long) = %zu\n", sizeof(long long));

    // sizeof 后面接变量也行，结果和接类型名一样
    printf("\n---- sizeof 测变量（字节）----\n");
    printf("sizeof(c)  = %zu\n", sizeof(c));
    printf("sizeof(s)  = %zu\n", sizeof(s));
    printf("sizeof(i)  = %zu\n", sizeof(i));
    printf("sizeof(l)  = %zu\n", sizeof(l));
    printf("sizeof(ll) = %zu\n", sizeof(ll));

    /* ========== 三、顺带看看各类型能存多大 ========== */
    printf("\n---- limits.h 里的取值范围 ----\n");
    printf("char       : %d ~ %d\n", CHAR_MIN, CHAR_MAX);
    printf("short      : %d ~ %d\n", SHRT_MIN, SHRT_MAX);
    printf("int        : %d ~ %d\n", INT_MIN, INT_MAX);
    printf("long       : %ld ~ %ld\n", LONG_MIN, LONG_MAX);
    printf("long long  : %lld ~ %lld\n", LLONG_MIN, LLONG_MAX);

    return 0;
}