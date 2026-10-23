#include <stdio.h>
#include <string.h>

/* 判断 s[l..r] 是否为回文 */
static int isPal(const char *s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return 0;
        l++;
        r--;
    }
    return 1;
}

int main(void) {
    char s[1005];
    scanf("%s", s);

    int n = (int)strlen(s);

    if (isPal(s, 0, n - 1)) {
        printf("Yes\n");
        return 0;
    }

    /* 尝试删掉左边或右边的一个字符 */
    int l = 0, r = n - 1;
    while (l < r && s[l] == s[r]) {
        l++;
        r--;
    }

    if (isPal(s, l + 1, r) || isPal(s, l, r - 1))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}