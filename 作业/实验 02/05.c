//
// Created by Admin on 2026/10/16.
//
#include <stdio.h>

int main() {
    int N, sq;
    scanf("%d", &N);
    sq = N * N;
    if (N <= 10) {
        if (N == sq % 10)printf("%d:这是同构数", N);
        if (N != sq % 10)printf("%d:这不是同构数", N);
    } else {
        if (N == sq % 100)printf("%d:这是同构数", N);
        if (N != sq % 100)printf("%d:这不是同构数", N);
    }
    return 0;
}
