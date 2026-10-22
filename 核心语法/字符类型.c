//
// Created by admin on 2026/10/22.
//
#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int main() {
    /* ========== 一、字符的定义 ========== */
    // 单引号，里面只能放一个字符
    char c     = 'A';
    char digit = '5';
    char ch    = 'x';

    printf("c=%c  digit=%c  ch=%c\n", c, digit, ch);

    /* ========== 二、字符的本质是整数 ========== */
    // 每个字符都对应一个 ASCII 码值，char 实际上就是 1 字节的整数
    printf("\n---- 字符就是整数 ----\n");
    printf("'A' 的码值 = %d\n", 'A');
    printf("'a' 的码值 = %d\n", 'a');
    printf("'0' 的码值 = %d\n", '0');
    printf("' ' 的码值 = %d\n", ' ');
    printf("'a' - 'A' = %d\n", 'a' - 'A');

    // 同一个变量，用 %c 打印是字符，用 %d 打印是码值
    printf("c 用 %%c 打印 = %c\n", c);
    printf("c 用 %%d 打印 = %d\n", c);

    /* ========== 三、字符和数字互相转换 ========== */
    // '0' ~ '9' 的码值是连续的，减 '0' 就能得到对应的数字
    printf("\n---- 字符 <-> 数字 ----\n");
    int n = digit - '0';               // '5' - '0' = 5
    printf("'5' - '0' = %d\n", n);
    printf("5 + '0'   = %c\n", n + '0');   // 再转回字符

    /* ========== 四、大小写转换 ========== */
    // 大写和小写字母的码值相差 32
    printf("\n---- 大小写转换 ----\n");
    printf("'A' + 32 = %c\n", c + 32);
    printf("'a' - 32 = %c\n", 'a' - 32);
    printf("toupper  = %c\n", toupper('a'));
    printf("tolower  = %c\n", tolower('A'));

    /* ========== 五、转义字符 ========== */
    // 以反斜杠开头的特殊字符，用来表示无法直接输入的字符
    printf("\n---- 转义字符 ----\n");
    printf("换行 \\n ：第一行\n第二行\n");
    printf("制表 \\t ：A\tB\tC\n");
    printf("反斜杠 \\\\ ：输出一个 \\\n");
    printf("单引号：'\n");
    printf("双引号：\"\n");

    /* ========== 六、sizeof 测量 ========== */
    printf("\n---- sizeof ----\n");
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(c)    = %zu\n", sizeof(c));
    // 注意：C 语言里字符常量 'A' 的类型是 int，不是 char
    printf("sizeof('A')  = %zu  <- C 里字符常量是 int\n", sizeof('A'));

    // 字符 vs 字符串：字符串多一个结尾的 '\0'
    printf("sizeof(\"A\")  = %zu  <- 字符串占 2 字节\n", sizeof("A"));

    /* ========== 七、char 的取值范围 ========== */
    // char 本身有没有符号由编译器决定，要明确就用 signed / unsigned
    printf("\n---- 取值范围 ----\n");
    printf("signed char  : %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: 0 ~ %d\n", UCHAR_MAX);

    return 0;
}