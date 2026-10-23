#include <stdio.h>

/*
 * f 形如 abc.d（100 <= f < 1000，且仅一位小数），翻转后为 d.cba。
 * 直接按字符读入再整串逆序输出，避免浮点误差。
 */
int main(void) {
    char s[32];
    scanf("%31s", s);

    int len = 0;
    while (s[len] != '\0') len++;

    for (int i = len - 1; i >= 0; i--) putchar(s[i]);
    putchar('\n');
    return 0;
}