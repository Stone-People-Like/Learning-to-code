//
// Created by admin on 2026/10/22.
//
#include <stdio.h>
int main() {
    int list[100];
    list[0] = 1;
    list[1] = 1;
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        list[i] = list[i - 1] + list[i - 2];
    }
    int fb=list[n-1];
    // printf("%0b\n", fb);
    int ones = __builtin_popcount(fb);
    int bits = 32 - __builtin_clz(fb);
    printf("%d",bits-  ones);
    // printf("%d",bits);
    return 0;
}