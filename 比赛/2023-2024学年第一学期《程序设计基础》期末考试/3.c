//
// Created by Admin on 2026/10/23.
//
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int list[10000];
    list[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &list[i]);
    }

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (list[i] % i == 0) sum++;
    }
    printf("%d", sum);
    return 0;
}
