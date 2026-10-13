#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int ans;
    if (a == 0) {
        ans = 1;
    } else {
        ans = a + 2 * b + 1;
    }
    printf("%d", ans);
    return 0;
}
