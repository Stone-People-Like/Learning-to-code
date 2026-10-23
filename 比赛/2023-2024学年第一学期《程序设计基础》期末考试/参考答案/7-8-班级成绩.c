#include <stdio.h>
#include <string.h>

typedef struct {
    char name[16];
    int math;
    int eng;
    int idx;
} Stu;

int main(void) {
    int n;
    scanf("%d", &n);

    static Stu s[105];
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", s[i].name, &s[i].math, &s[i].eng);
        s[i].idx = i;
    }

    /* 最高/最低（并列取最先出现） */
    int minM = 0, maxM = 0, minE = 0, maxE = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].math < s[minM].math) minM = i;
        if (s[i].math > s[maxM].math) maxM = i;
        if (s[i].eng < s[minE].eng) minE = i;
        if (s[i].eng > s[maxE].eng) maxE = i;
    }
    printf("%s %d %s %d\n", s[minM].name, s[minM].math, s[maxM].name, s[maxM].math);
    printf("%s %d %s %d\n", s[minE].name, s[minE].eng, s[maxE].name, s[maxE].eng);

    /* 按总分、高数、英语、出现次序排序 */
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int ti = s[i].math + s[i].eng, tj = s[j].math + s[j].eng;
            int swap = 0;
            if (tj > ti) swap = 1;
            else if (tj == ti) {
                if (s[j].math > s[i].math) swap = 1;
                else if (s[j].math == s[i].math) {
                    if (s[j].eng > s[i].eng) swap = 1;
                    else if (s[j].eng == s[i].eng && s[j].idx < s[i].idx) swap = 1;
                }
            }
            if (swap) {
                Stu t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }

    for (int i = 0; i < n; i++)
        printf("%s %d %d\n", s[i].name, s[i].math, s[i].eng);
    return 0;
}