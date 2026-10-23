#include <stdio.h>
#include <string.h>

/*
 * 1) 字符串中已存在 "nelay" → 输出其中 'n' 的下标；
 * 2) 否则最多改一个字符使其出现 → 输出该字符下标（取最小合法下标）；
 * 3) 否则输出第一个 'y' 的下标。
 */
int main(void) {
    int n;
    scanf("%d", &n);

    char s[1005];
    scanf("%s", s);

    const char *pat = "nelay";

    /* 1) 已有完整子串 */
    for (int i = 0; i + 5 <= n; i++) {
        if (strncmp(s + i, pat, 5) == 0) {
            printf("%d\n", i);
            return 0;
        }
    }

    /* 2) 差一个字符即可构成 */
    for (int i = 0; i + 5 <= n; i++) {
        int diff = 0, pos = -1;
        for (int j = 0; j < 5; j++) {
            if (s[i + j] != pat[j]) {
                diff++;
                pos = i + j;
            }
        }
        if (diff == 1) {
            printf("%d\n", pos);
            return 0;
        }
    }

    /* 3) 输出第一个 'y' */
    for (int i = 0; i < n; i++) {
        if (s[i] == 'y') {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}