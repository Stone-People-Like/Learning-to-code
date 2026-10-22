//
// Created by admin on 2026/10/22.
//
#include <stdio.h>

int main() {
    /* ========== 一、最基本的键盘录入 ========== */
    // scanf 是格式化输入函数，从键盘读数据
    // 关键：变量前面必须加 &（取地址符），因为 scanf 要知道把数据写到哪
    int age;
    printf("请输入年龄: ");
    scanf("%d", &age);
    printf("你输入的年龄是 %d\n", age);

    /* ========== 二、一次输入多个值 ========== */
    // 格式串里用空格、逗号都可以指定分隔方式
    // 用空格时，实际输入的空格、Tab、回车都算分隔符
    int a, b;
    printf("\n请输入两个整数（用空格分开）: ");
    scanf("%d %d", &a, &b);
    printf("a = %d, b = %d\n", a, b);

    /* ========== 三、不同数据类型的格式符 ========== */
    // float 用 %f，double 必须用 %lf，两者不能混
    float  height;
    double weight;
    printf("\n请输入身高（米）: ");
    scanf("%f", &height);
    printf("请输入体重（kg）: ");
    scanf("%lf", &weight);
    printf("身高 = %.2f 米, 体重 = %.2f kg\n", height, weight);

    /* ========== 四、字符输入的换行符陷阱 ========== */
    // %c 会老老实实读一个字符，包括空格和回车
    // 上一步按回车后，缓冲区里还留着一个 '\n'，会被 %c 直接读走
    // 解决办法：在 %c 前面加一个空格，表示「跳过所有空白字符」
    char grade;
    printf("\n请输入等级（A/B/C）: ");
    scanf(" %c", &grade);
    printf("你的等级是 %c\n", grade);

    /* ========== 五、字符串输入 ========== */
    // 字符串用字符数组存，%s 遇到空格或回车就停
    // 数组名本身就是地址，所以不用加 &
    char name[20];
    printf("\n请输入名字（不要有空格）: ");
    scanf("%s", name);
    printf("你好，%s\n", name);

    /* ========== 六、scanf 的返回值 ========== */
    // 返回值是「成功读到的项数」，可以用来判断输入是否合法
    int score;
    printf("\n请输入分数: ");
    int ret = scanf("%d", &score);
    if (ret == 1) {
        printf("读取成功，分数 = %d\n", score);
    } else {
        printf("读取失败，返回值 = %d\n", ret);
    }

    /* ========== 常见错误（写出来会出问题，只放在注释里） ========== */
    // scanf("%d", age);         // 错误：少了 &，程序会崩溃
    // scanf("%f", &weight);     // 错误：double 必须用 %lf
    // scanf("%lf", &height);    // 错误：float 用 %lf 会越界写 8 字节
    // scanf("%s", &name);       // 错误：数组名已经是地址，不用再加 &

    return 0;
}