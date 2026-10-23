#include <stdio.h>
#include <ctype.h>

/*
 * 元素：A B C D 为强元素（火水雷冰），a b c d 为弱元素，E 为风元素。
 * 规则：
 *   弱+弱：d1+d2+d1*d2，无附着
 *   强+弱：d1+d2+2*d1*d2，强元素附着
 *   强+强：d1+d2+3*d1*d2，双方都变弱且都附着
 *   弱扩散： (d1+d2)*2，无附着
 *   强扩散： (2*d1+d2)*2，附着强元素
 *   同元素：d1+d2，只附着一次（强覆盖弱）
 */
int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        char ch1, ch2;
        long long d1, d2;
        scanf(" %c %c %lld %lld", &ch1, &ch2, &d1, &d2);

        int s1 = (ch1 >= 'A' && ch1 <= 'D');   /* ch1 是否强元素 */
        int s2 = (ch2 >= 'A' && ch2 <= 'D');
        long long sum;

        if (ch2 == 'E') {
            /* 扩散：ch1 必不为风 */
            sum = s1 ? (2 * d1 + d2) * 2 : (d1 + d2) * 2;
            printf("%lld\n", sum);
            if (s1) printf("%c\n", ch1);
            continue;
        }

        char b1 = (char)tolower((unsigned char)ch1);
        char b2 = (char)tolower((unsigned char)ch2);

        if (b1 == b2) {
            /* 同元素，不发生反应 */
            sum = d1 + d2;
            printf("%lld\n", sum);
            printf("%c\n", (s1 || s2) ? (char)toupper((unsigned char)b1) : b1);
        } else if (s1 && s2) {
            sum = d1 + d2 + 3 * d1 * d2;
            printf("%lld\n", sum);
            printf("%c %c\n", b1, b2);
        } else if (s1 || s2) {
            sum = d1 + d2 + 2 * d1 * d2;
            printf("%lld\n", sum);
            printf("%c\n", s1 ? ch1 : ch2);
        } else {
            sum = d1 + d2 + d1 * d2;
            printf("%lld\n", sum);
        }
    }
    return 0;
}