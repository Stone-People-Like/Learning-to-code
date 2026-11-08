//
// Created by admin on 2026/10/24.
//
#include <stdio.h>

int main() {
    int list[3];
    int flag=0;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=0;i<3;i++) {
        scanf("%d",&list[i]);
    }
    for (int i=0;i<3;i++) {
        if (list[i]<=60) {
            flag=1;
        }
    }
    if (flag==1) {
        printf("You are not our friends\n");
    }else {
        printf("You are not our enemy either\n");
    }
    return 0;
}