#include  <stdio.h>

int main() {
    int GoodSum = 0;
    // 程序的输入部分
    int N, L, R;
    scanf("%d%d%d", &N, &L, &R);
    // 算法部分
    // 判断总共坏的页数
    if (L % 2 == 0) {
        L--;
        GoodSum++;
    }
    if (R % 2 == 1) {
        R++;
        GoodSum++;
    }
    if (N % 2 == 1 && (R - 1) == N) {
        --GoodSum;
    }
    int deffSum;
    deffSum = (R - L + 1) / 2;
    printf("%d %d", deffSum, GoodSum);
    // 输出控制
    return 0;
}
