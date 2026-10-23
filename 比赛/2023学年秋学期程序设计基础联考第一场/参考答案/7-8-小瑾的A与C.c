#include <stdio.h>

/*
 * 把成绩中的 'C' 改成 'A'，并把这些修改过的 A 全部放到序列末尾，
 * 其余字符保持原相对顺序。
 */
int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);

        char s[100005];
        for (int i = 0; i < n; i++) scanf(" %c", &s[i]);

        int cntC = 0;
        for (int i = 0; i < n; i++) if (s[i] == 'C') cntC++;

        int first = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'C') continue;
            if (!first) putchar(' ');
            putchar(s[i]);
            first = 0;
        }
        for (int i = 0; i < cntC; i++) {
            if (!first) putchar(' ');
            putchar('A');
            first = 0;
        }
        putchar('\n');
    }
    return 0;
}