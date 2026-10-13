//
// Created by Admin on 2026/10/13.
//
#include <stdio.h>

int main() {
    int h1time1, m1time1, h2time1, m2time1;
    int h1time2, m1time2, h2time2, m2time2;
    int h1time3, m1time3, h2time3, m2time3;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",
          &h1time1, &h2time1, &m1time1, &m2time1,
          &h1time2, &h2time2, &m1time2, &m2time2,
          &h1time3, &h2time3, &m1time3, &m2time3
    );

    int Time1, Time2, Time3;
    Time1 = h1time1 - h2time1;
    Time2 = h1time2 - h2time2;
    Time3 = h1time3 - h2time3;
    printf("%d\n", Time1);
    printf("%d\n", h1time1);
    printf("%d\n", h2time1);
    return 0;
}
