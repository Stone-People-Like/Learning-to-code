#include <stdio.h>

static int isPalindrome(int v) {
    int d[12], n = 0;
    while (v > 0) {
        d[n++] = v % 10;
        v /= 10;
    }
    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (d[i] != d[j]) return 0;
    return 1;
}

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);

    int cnt = 0;
    for (int v = x; v <= y; v++)
        if (isPalindrome(v)) cnt++;

    printf("%d\n", cnt);
    return 0;
}