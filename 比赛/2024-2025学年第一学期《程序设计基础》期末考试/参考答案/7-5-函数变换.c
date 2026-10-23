#include <stdio.h>

/*
 * 要求 f(s1,s2)[i] = min(s1[i], s2[i]) = s3[i]。
 * 分析每个位置：
 *   s1[i] <  s3[i]：min 不可能大于 s1[i]，无解 → 输出 NO；
 *   s1[i] == s3[i]：需要 s2[i] >= s1[i]，字典序最小取 s2[i] = s3[i]；
 *   s1[i] >  s3[i]：必须 s2[i] == s3[i]。
 * 因此只要逐位满足 s1[i] >= s3[i]，s2 = s3 即为字典序最小解。
 */
int main(void) {
    int n;
    scanf("%d", &n);

    char s1[128], s3[128];
    scanf("%s", s1);
    scanf("%s", s3);

    for (int i = 0; i < n; i++) {
        if (s1[i] < s3[i]) {
            printf("NO\n");
            return 0;
        }
    }

    printf("%s\n", s3);
    return 0;
}