//
// Created by admin on 2026/10/22.
//
#include <stdio.h>

/* ========== 一、合法的标识符 ========== */
// 规则：只能由 字母、数字、下划线 组成，并且不能以数字开头
int studentAge  = 20;    // 驼峰命名，变量名首字母小写
int student_age = 21;    // 下划线命名，单词之间用 _
int count2      = 30;    // 数字可以出现在中间或末尾，只是不能开头

#define MAX_SIZE 100     // 宏名习惯全部大写，用来和变量区分

// 函数名也是标识符，规则完全一样
int add(int a, int b) {
    return a + b;
}

int main() {
    int _temp = 1;           // 下划线开头合法，但这类名字可能被编译器占用

    printf("studentAge  = %d\n", studentAge);
    printf("student_age = %d\n", student_age);
    printf("count2      = %d\n", count2);
    printf("_temp       = %d\n", _temp);
    printf("MAX_SIZE    = %d\n", MAX_SIZE);
    printf("add(1, 2)   = %d\n", add(1, 2));

    /* ========== 二、区分大小写 ========== */
    // C 语言区分大小写，下面三个是完全不同的标识符
    int Age = 18;
    int age = 30;
    int AGE = 40;
    printf("\nAge=%d  age=%d  AGE=%d  <- 三个不同的变量\n", Age, age, AGE);

    // 关键字小写，但首字母大写的 Int 是合法的标识符（不推荐这么写）
    int Int = 5;
    printf("Int=%d  <- 合法，因为 Int 不是关键字\n", Int);

    /* ========== 三、非法的标识符 ========== */
    // 下面这些写出来会直接编译报错，所以只能放在注释里
    // int 2count = 0;     // 错误：不能以数字开头
    // int my-var = 0;     // 错误：减号不是合法字符
    // int my var = 0;     // 错误：不能包含空格
    // int int = 0;        // 错误：int 是关键字
    // int #value = 0;     // 错误：# 不是合法字符

    printf("\n---- 合法 / 非法对照 ----\n");
    printf("合法：studentAge  student_age  count2  _temp  MAX_SIZE\n");
    printf("非法：2count      my-var       my var  int    #value\n");

    return 0;
}