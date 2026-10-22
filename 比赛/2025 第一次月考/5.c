//
// Created by admin on 2026/10/22.
//
#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        //TODO
        if (i<1)printf("   +---+\n");
        //printf("\n");
        printf("  /     \\\n");
        //printf("\n");
        printf(" +       +\n");
        //printf("\n");
        printf("  \\     /\n");
        //printf("\n");
        printf("   +---+\n");
    }

    return 0;
}