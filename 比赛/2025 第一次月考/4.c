//
// Created by Admin on 2026/10/22.
//
#include <stdio.h>

int main() {
    int n;
    int b[10];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        // printf("%d", b[i]);
        if (b[i]%2!=0)sum+=b[i];
    }
    printf("%d", sum);
    return 0;
}
