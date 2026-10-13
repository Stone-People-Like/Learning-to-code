//
// Created by Admin on 2026/10/13.
//
#include <stdio.h>

int main() {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int Diffx, Diffy, max;
    Diffx = x1 - x2;
    Diffy = y1 - y2;
    if (Diffx < 0) Diffx = -Diffx;
    if (Diffy < 0) Diffy = -Diffy;
    max = Diffx;
    if (Diffx < Diffy) max = Diffy;
    printf("%d %d", Diffx + Diffy, max);
    return 0;
}
