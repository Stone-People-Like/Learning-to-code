#include <stdio.h>
#include <stdlib.h>

/*
 * 每条选课记录需要支持：
 *   选课：若未满则直接加入；若已满且该生属于优先班级，则踢掉最晚选课的非优先学生；
 *   退课：从课程中移除该生。
 * 课程人数上限 <= 200，操作数 <= 1e5，直接维护每门课的选课列表（按选课先后顺序）即可。
 */

#define MAXC 1005
#define MAXL 205

typedef struct {
    int lim;
    int prefClass;
    int cnt;
    int stu[MAXL];      /* 按选课时间先后排列 */
} Course;

static Course course[MAXC];

/* 学生最多 20 门课，这里用位图记录以便退课与查询 */
static unsigned int enrolled[10005];   /* 每门课占 1 bit，n <= 1000 */
static int myCount[10005];

static int classOf(int sid) { return (sid - 1) / 40 + 1; }

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &course[i].prefClass, &course[i].lim);
        course[i].cnt = 0;
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        int sid, cid, opt;
        scanf("%d %d %d", &sid, &cid, &opt);

        int bit = 1 << (cid & 31);
        int word = cid >> 5;
        (void)bit; (void)word;

        if (opt == 1) {
            /* 已选则忽略 */
            if (myCount[sid] >= 20) continue;
            int already = 0;
            for (int i = 0; i < course[cid].cnt; i++)
                if (course[cid].stu[i] == sid) { already = 1; break; }
            if (already) continue;

            int inPref = (classOf(sid) == course[cid].prefClass);

            if (course[cid].cnt < course[cid].lim) {
                course[cid].stu[course[cid].cnt++] = sid;
                myCount[sid]++;
            } else if (inPref) {
                /* 找最晚选课的非优先学生 */
                int victim = -1;
                for (int i = course[cid].cnt - 1; i >= 0; i--) {
                    if (classOf(course[cid].stu[i]) != course[cid].prefClass) {
                        victim = i;
                        break;
                    }
                }
                if (victim >= 0) {
                    int vsid = course[cid].stu[victim];
                    myCount[vsid]--;
                    /* 删除该位置，后面的前移 */
                    for (int i = victim; i + 1 < course[cid].cnt; i++)
                        course[cid].stu[i] = course[cid].stu[i + 1];
                    course[cid].cnt--;
                    course[cid].stu[course[cid].cnt++] = sid;
                    myCount[sid]++;
                }
            }
        } else {
            for (int i = 0; i < course[cid].cnt; i++) {
                if (course[cid].stu[i] == sid) {
                    for (int j = i; j + 1 < course[cid].cnt; j++)
                        course[cid].stu[j] = course[cid].stu[j + 1];
                    course[cid].cnt--;
                    myCount[sid]--;
                    break;
                }
            }
        }
    }

    int target;
    scanf("%d", &target);

    int list[1005], cnt = 0;
    for (int c = 1; c <= n; c++)
        for (int i = 0; i < course[c].cnt; i++)
            if (course[c].stu[i] == target) list[cnt++] = c;

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        if (i) putchar(' ');
        printf("%d", list[i]);
    }
    putchar('\n');
    return 0;
}