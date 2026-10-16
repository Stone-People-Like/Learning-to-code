//
// Created by Admin on 2026/10/16.
//
#include <stdio.h>

int main() {
    int N;
    int flag = 0; //初始等于 0,代表是素数
    scanf("%d", &N);
    if (N <= 2) {
        printf("应输入大于 2 的整数");
    } else {
        for (int i = 2; i < N - 1; ++i) {
            if (N % i == 0) flag = 1; // 如果除尽了flag 等于 1，代表是素数
        }
    }
    if (flag == 1) printf("这不是一个素数");
    if (flag == 0) printf("这是一个素数");
    return 0;
}
