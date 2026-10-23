#include <stdio.h>

/* 统计十进制中偶数数位（0,2,4,6,8）的出现次数。 */
int main(void) {
    char s[32];
    scanf("%31s", s);

    int cnt = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if ((s[i] - '0') % 2 == 0) cnt++;

    printf("%d\n", cnt);
    return 0;
}