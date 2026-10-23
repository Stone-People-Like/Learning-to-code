//
// Created by Admin on 2026/10/23.
//
#include <stdio.h>
#include <sys/resource.h>

int main() {
    int a, b;
    char f;
    scanf("%d%d %c", &a, &b, &f);
    if (b == 0) {
        printf("NaN");
        return 0;
    }
    if (f == '+')printf("%d", a + b);
    if (f == '-')printf("%d", a - b);
    if (f == '*')printf("%d", a * b);
    if (f == '/')printf("%d", a / b);
    return 0;
}
