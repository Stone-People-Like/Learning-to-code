#include <stdio.h>

/*
 * 队首两人对打，强者留下，弱者排到队尾。
 * 战最强者一旦登场就会永远守擂，所以只需模拟「最强者登场之前」的场次
 * （最多 n-1 场）；若此前没人达到 k 胜，答案就是全体战力的最大值。
 */
#define MAXN 505

int main(void) {
    int n;
    long long k;
    long long a[MAXN];
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

    long long champ = a[0];
    long long wins = 0;

    /* 队列：head 指向队首，未登场的人按原顺序补在尾部 */
    for (int i = 1; i < n; i++) {
        long long challenger = a[i];
        if (champ > challenger) {
            wins++;
        } else {
            champ = challenger;
            wins = 1;
        }
        if (wins >= k) {
            printf("%lld\n", champ);
            return 0;
        }
    }
    /* 最强者已在场上，剩余场次它会一路赢下去 */
    printf("%lld\n", champ);
    return 0;
}