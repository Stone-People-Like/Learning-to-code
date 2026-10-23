//
// Created by Admin on 2026/10/23.
//
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int list[100];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &list[i]);
    }
    int min = list[0];
    for (int i = 1; i < n; ++i) {
        if (min > list[i]) min = list[i];
    }
    printf("%d", min);
    return 0;
}
