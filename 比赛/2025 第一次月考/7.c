//
// Created by admin on 2026/10/22.
//
#include <stdio.h>

int main() {
    int n, k;
    int list[100000];
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &list[i]);
    }
    int max = list[0];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (max > list[i]) {
            max = list[i];
            sum++;
        }
        if (sum == k) {
            printf("%d", list[i - 1]);
            return 0;
        }
    }
    return 0;
}
