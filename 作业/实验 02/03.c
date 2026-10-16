//
// Created by Admin on 2026/10/16.
//
#include <stdio.h>
#define  PI  3.1415926

int main() {
    double r1, r2;
    scanf("%lf%lf", &r1, &r2);
    double End;
    End = PI * r2 * r2 - PI * r1 * r1;
    printf("%.2f", End);
    return 0;
}
