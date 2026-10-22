//
// Created by admin on 2026/10/22.
//
#include <stdio.h>
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    if (n==m){printf("Yes");return 0;}
    if (n<m){printf("No");return 0;}
    if (n % 2 != 0 && m % 2 != 0) { printf("Yes"); return 0; }
    if (n % 2 == 0 && m % 2 == 0) { printf("Yes"); return 0; }
    printf("No");
    return 0;
}