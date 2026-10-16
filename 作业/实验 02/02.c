//
// Created by Admin on 2026/10/16.
//
#include <stdio.h>

int main() {
    int dayN;
    scanf("%d", &dayN);
    int y, m, d;
    y = dayN / 365; //用来判断年份
    m = (dayN - y * 365) / 30; //用来判断年份
    d = dayN - y * 365 - m * 30; //用来判断年份
    printf("%d年%d个月%d天", y, m, d);
    return 0;
}
