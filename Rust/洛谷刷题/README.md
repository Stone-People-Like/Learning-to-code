# 洛谷刷题路线（Rust）

> 用洛谷题单驱动 Rust 学习 — 题目源自洛谷官方题单，共 18 个题单 / 271 题

## 使用方式

- 按下面的阶段顺序推进，每道题都用 **Rust** 写，不要用顺手的老语言
- 状态标记：⬜ 未开始 / 🟨 进行中 / ✅ 已通过 / ⭐ 已通过且自己满意
- 卡住时把题目链接和你的代码一起发出来讨论
- 本地在 `Rust/洛谷刷题/<题号>/` 建 Cargo 项目调试，通过后再提交洛谷

## 推荐路线总览

| 阶段 | 内容 | 题单 | 题数 |
|------|------|------|------|
| 阶段一 · 语法入门 | 把 Rust 基本语法、输入输出、控制流跑通 | 100, 101, 102 | 54 |
| 阶段二 · 数据组织 | 数组、字符串、函数与结构体，对应 Vec / String / struct / 所有权初步 | 103, 104, 105 | 50 |
| 阶段三 · 基础算法 | 模拟、排序、枚举、递推递归，练手写实现而非调库 | 106, 107, 108, 109 | 57 |
| 阶段四 · 稍难算法 | 贪心、二分、搜索，开始接触闭包与迭代器风格 | 110, 111, 112 | 41 |
| 阶段五 · 数据结构 | 线性表、二叉树、集合、图，用 Rust 手写递归类型（Box / Rc / RefCell） | 113, 114, 115, 116 | 45 |
| 阶段六 · 数学 | 数论与组合基础，练整数边界与溢出处理 | 117 | 24 |

---

## 阶段一 · 语法入门

把 Rust 基本语法、输入输出、控制流跑通


### 【入门1】顺序结构（题单 100，15 题）

<https://www.luogu.com.cn/training/100>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [B2002](https://www.luogu.com.cn/problem/B2002) | Hello,World! | ⬜ |
| 2 | [B2025](https://www.luogu.com.cn/problem/B2025) | 输出字符菱形 | ⬜ |
| 3 | [P1000](https://www.luogu.com.cn/problem/P1000) | 超级玛丽游戏 | ⬜ |
| 4 | [P1001](https://www.luogu.com.cn/problem/P1001) | A+B Problem | ⬜ |
| 5 | [B2005](https://www.luogu.com.cn/problem/B2005) | 字符三角形 | ⬜ |
| 6 | [P5703](https://www.luogu.com.cn/problem/P5703) | 【深基2.例5】苹果采购 | ⬜ |
| 7 | [P5704](https://www.luogu.com.cn/problem/P5704) | 【深基2.例6】字母转换 | ⬜ |
| 8 | [P5705](https://www.luogu.com.cn/problem/P5705) | 【深基2.例7】数字反转 | ⬜ |
| 9 | [P5706](https://www.luogu.com.cn/problem/P5706) | 【深基2.例8】再分肥宅水 | ⬜ |
| 10 | [P5708](https://www.luogu.com.cn/problem/P5708) | 【深基2.习2】三角形面积 | ⬜ |
| 11 | [P5707](https://www.luogu.com.cn/problem/P5707) | 【深基2.例12】上学迟到 | ⬜ |
| 12 | [B2029](https://www.luogu.com.cn/problem/B2029) | 大象喝水 | ⬜ |
| 13 | [P1425](https://www.luogu.com.cn/problem/P1425) | 小鱼的游泳时间 | ⬜ |
| 14 | [P1421](https://www.luogu.com.cn/problem/P1421) | 小玉买文具 | ⬜ |
| 15 | [P3954](https://www.luogu.com.cn/problem/P3954) | [NOIP 2017 普及组] 成绩 | ⬜ |

### 【入门2】分支结构（题单 101，18 题）

<https://www.luogu.com.cn/training/101>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P2433](https://www.luogu.com.cn/problem/P2433) | 【深基1-2】小学数学 N 合一 | ⬜ |
| 2 | [P5709](https://www.luogu.com.cn/problem/P5709) | 【深基2.习6】Apples Prologue / 苹果和虫子 | ⬜ |
| 3 | [P5710](https://www.luogu.com.cn/problem/P5710) | 【深基3.例2】数的性质 | ⬜ |
| 4 | [P5711](https://www.luogu.com.cn/problem/P5711) | 【深基3.例3】闰年判断 | ⬜ |
| 5 | [P5712](https://www.luogu.com.cn/problem/P5712) | 【深基3.例4】Apples | ⬜ |
| 6 | [P5713](https://www.luogu.com.cn/problem/P5713) | 【深基3.例5】洛谷团队系统 | ⬜ |
| 7 | [P5714](https://www.luogu.com.cn/problem/P5714) | 【深基3.例7】肥胖问题 | ⬜ |
| 8 | [P5715](https://www.luogu.com.cn/problem/P5715) | 【深基3.例8】三位数排序 | ⬜ |
| 9 | [P5716](https://www.luogu.com.cn/problem/P5716) | 【深基3.例9】月份天数 | ⬜ |
| 10 | [P1085](https://www.luogu.com.cn/problem/P1085) | [NOIP 2004 普及组] 不高兴的津津 | ⬜ |
| 11 | [P1909](https://www.luogu.com.cn/problem/P1909) | [NOIP 2016 普及组] 买铅笔 | ⬜ |
| 12 | [P5717](https://www.luogu.com.cn/problem/P5717) | 【深基3.习8】三角形分类 | ⬜ |
| 13 | [P1422](https://www.luogu.com.cn/problem/P1422) | 小玉家的电费 | ⬜ |
| 14 | [P1424](https://www.luogu.com.cn/problem/P1424) | 小鱼的航程（改进版） | ⬜ |
| 15 | [P1888](https://www.luogu.com.cn/problem/P1888) | 三角函数 | ⬜ |
| 16 | [P1046](https://www.luogu.com.cn/problem/P1046) | [NOIP 2005 普及组] 陶陶摘苹果 | ⬜ |
| 17 | [P4414](https://www.luogu.com.cn/problem/P4414) | [COCI 2006/2007 #2] ABC | ⬜ |
| 18 | [P1055](https://www.luogu.com.cn/problem/P1055) | [NOIP 2008 普及组] ISBN 号码 | ⬜ |

### 【入门3】循环结构（题单 102，21 题）

<https://www.luogu.com.cn/training/102>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P5718](https://www.luogu.com.cn/problem/P5718) | 【深基4.例2】找最小值 | ⬜ |
| 2 | [P5719](https://www.luogu.com.cn/problem/P5719) | 【深基4.例3】分类平均 | ⬜ |
| 3 | [P5720](https://www.luogu.com.cn/problem/P5720) | 【深基4.例4】一尺之棰 | ⬜ |
| 4 | [P5721](https://www.luogu.com.cn/problem/P5721) | 【深基4.例6】数字直角三角形 | ⬜ |
| 5 | [P1009](https://www.luogu.com.cn/problem/P1009) | [NOIP 1998 普及组] 阶乘之和 | ⬜ |
| 6 | [P1980](https://www.luogu.com.cn/problem/P1980) | [NOIP 2013 普及组] 计数问题 | ⬜ |
| 7 | [P1035](https://www.luogu.com.cn/problem/P1035) | [NOIP 2002 普及组] 级数求和 | ⬜ |
| 8 | [P2669](https://www.luogu.com.cn/problem/P2669) | [NOIP 2015 普及组] 金币 | ⬜ |
| 9 | [P5722](https://www.luogu.com.cn/problem/P5722) | 【深基4.例11】数列求和 | ⬜ |
| 10 | [P5723](https://www.luogu.com.cn/problem/P5723) | 【深基4.例13】质数口袋 | ⬜ |
| 11 | [P1217](https://www.luogu.com.cn/problem/P1217) | [USACO1.5] Prime Palindromes | ⬜ |
| 12 | [P1423](https://www.luogu.com.cn/problem/P1423) | 小玉在游泳 | ⬜ |
| 13 | [P1307](https://www.luogu.com.cn/problem/P1307) | [NOIP 2011 普及组] 数字反转 | ⬜ |
| 14 | [P1720](https://www.luogu.com.cn/problem/P1720) | 月落乌啼算钱（斐波那契数列） | ⬜ |
| 15 | [P5724](https://www.luogu.com.cn/problem/P5724) | 【深基4.习5】求极差 / 最大跨度值 / 最大值和最小值的差 | ⬜ |
| 16 | [P1420](https://www.luogu.com.cn/problem/P1420) | 最长连号 | ⬜ |
| 17 | [P1075](https://www.luogu.com.cn/problem/P1075) | [NOIP 2012 普及组] 质因数分解 | ⬜ |
| 18 | [P5725](https://www.luogu.com.cn/problem/P5725) | 【深基4.习8】求三角形 | ⬜ |
| 19 | [P5726](https://www.luogu.com.cn/problem/P5726) | 【深基4.习9】打分 | ⬜ |
| 20 | [P4956](https://www.luogu.com.cn/problem/P4956) | [COCI 2017/2018 #6] Davor | ⬜ |
| 21 | [P1089](https://www.luogu.com.cn/problem/P1089) | [NOIP 2004 提高组] 津津的储蓄计划 | ⬜ |

---

## 阶段二 · 数据组织

数组、字符串、函数与结构体，对应 Vec / String / struct / 所有权初步


### 【入门4】数组（题单 103，20 题）

<https://www.luogu.com.cn/training/103>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P1428](https://www.luogu.com.cn/problem/P1428) | 小鱼比可爱 | ⬜ |
| 2 | [P1427](https://www.luogu.com.cn/problem/P1427) | 小鱼的数字游戏 | ⬜ |
| 3 | [P5727](https://www.luogu.com.cn/problem/P5727) | 【深基5.例3】冰雹猜想 | ⬜ |
| 4 | [P1047](https://www.luogu.com.cn/problem/P1047) | [NOIP 2005 普及组] 校门外的树 | ⬜ |
| 5 | [P5728](https://www.luogu.com.cn/problem/P5728) | 【深基5.例5】旗鼓相当的对手 | ⬜ |
| 6 | [P5729](https://www.luogu.com.cn/problem/P5729) | 【深基5.例7】工艺品制作 | ⬜ |
| 7 | [P2550](https://www.luogu.com.cn/problem/P2550) | [AHOI2001] 彩票摇奖 | ⬜ |
| 8 | [P2615](https://www.luogu.com.cn/problem/P2615) | [NOIP 2015 提高组] 神奇的幻方 | ⬜ |
| 9 | [P5730](https://www.luogu.com.cn/problem/P5730) | 【深基5.例10】显示屏 | ⬜ |
| 10 | [P1554](https://www.luogu.com.cn/problem/P1554) | [USACO06DEC] 梦中的统计 Dream Counting B | ⬜ |
| 11 | [P2141](https://www.luogu.com.cn/problem/P2141) | [NOIP 2014 普及组] 珠心算测验 | ⬜ |
| 12 | [P1614](https://www.luogu.com.cn/problem/P1614) | 爱与愁的心痛 | ⬜ |
| 13 | [P2911](https://www.luogu.com.cn/problem/P2911) | [USACO08OCT] Bovine Bones G | ⬜ |
| 14 | [P1161](https://www.luogu.com.cn/problem/P1161) | 开灯 | ⬜ |
| 15 | [P5731](https://www.luogu.com.cn/problem/P5731) | 【深基5.习6】蛇形方阵 | ⬜ |
| 16 | [P5732](https://www.luogu.com.cn/problem/P5732) | 【深基5.习7】杨辉三角 | ⬜ |
| 17 | [P1789](https://www.luogu.com.cn/problem/P1789) | 【Mc生存】插火把 | ⬜ |
| 18 | [P1319](https://www.luogu.com.cn/problem/P1319) | 压缩技术 | ⬜ |
| 19 | [P1320](https://www.luogu.com.cn/problem/P1320) | 压缩技术（续集版） | ⬜ |
| 20 | [P1205](https://www.luogu.com.cn/problem/P1205) | [USACO1.2] Transformations | ⬜ |

### 【入门5】字符串（题单 104，15 题）

<https://www.luogu.com.cn/training/104>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P5733](https://www.luogu.com.cn/problem/P5733) | 【深基6.例1】自动修正 | ⬜ |
| 2 | [P1914](https://www.luogu.com.cn/problem/P1914) | 小书童——凯撒密码 | ⬜ |
| 3 | [P1125](https://www.luogu.com.cn/problem/P1125) | [NOIP 2008 提高组] 笨小猴 | ⬜ |
| 4 | [P1957](https://www.luogu.com.cn/problem/P1957) | 口算练习题 | ⬜ |
| 5 | [P5015](https://www.luogu.com.cn/problem/P5015) | [NOIP 2018 普及组] 标题统计 | ⬜ |
| 6 | [P5734](https://www.luogu.com.cn/problem/P5734) | 【深基6.例6】文字处理软件 | ⬜ |
| 7 | [P1308](https://www.luogu.com.cn/problem/P1308) | [NOIP 2011 普及组] 统计单词数 | ⬜ |
| 8 | [P1765](https://www.luogu.com.cn/problem/P1765) | 手机 | ⬜ |
| 9 | [P3741](https://www.luogu.com.cn/problem/P3741) | 小果的键盘 | ⬜ |
| 10 | [P1321](https://www.luogu.com.cn/problem/P1321) | 单词覆盖还原 | ⬜ |
| 11 | [P1553](https://www.luogu.com.cn/problem/P1553) | 数字反转（升级版） | ⬜ |
| 12 | [P1603](https://www.luogu.com.cn/problem/P1603) | 斯诺登的密码 | ⬜ |
| 13 | [P1200](https://www.luogu.com.cn/problem/P1200) | [USACO1.1] Your Ride Is Here | ⬜ |
| 14 | [P1597](https://www.luogu.com.cn/problem/P1597) | 语句解析 | ⬜ |
| 15 | [P1598](https://www.luogu.com.cn/problem/P1598) | [USACO03FEB] 垂直柱状图 Vertical Histogram | ⬜ |

### 【入门6】函数与结构体（题单 105，15 题）

<https://www.luogu.com.cn/training/105>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P5735](https://www.luogu.com.cn/problem/P5735) | 【深基7.例1】距离函数 | ⬜ |
| 2 | [P5736](https://www.luogu.com.cn/problem/P5736) | 【深基7.例2】质数筛 | ⬜ |
| 3 | [P5737](https://www.luogu.com.cn/problem/P5737) | 【深基7.例3】闰年展示 | ⬜ |
| 4 | [P5738](https://www.luogu.com.cn/problem/P5738) | 【深基7.例4】歌唱比赛 | ⬜ |
| 5 | [P5739](https://www.luogu.com.cn/problem/P5739) | 【深基7.例7】计算阶乘 | ⬜ |
| 6 | [P5461](https://www.luogu.com.cn/problem/P5461) | 赦免战俘 | ⬜ |
| 7 | [P5740](https://www.luogu.com.cn/problem/P5740) | 【深基7.例9】最厉害的学生 | ⬜ |
| 8 | [P5741](https://www.luogu.com.cn/problem/P5741) | 【深基7.例10】旗鼓相当的对手 - 加强版 | ⬜ |
| 9 | [P5742](https://www.luogu.com.cn/problem/P5742) | 【深基7.例11】评等级 | ⬜ |
| 10 | [P1075](https://www.luogu.com.cn/problem/P1075) | [NOIP 2012 普及组] 质因数分解 | ⬜ |
| 11 | [P1304](https://www.luogu.com.cn/problem/P1304) | 哥德巴赫猜想 | ⬜ |
| 12 | [P1217](https://www.luogu.com.cn/problem/P1217) | [USACO1.5] Prime Palindromes | ⬜ |
| 13 | [P2415](https://www.luogu.com.cn/problem/P2415) | 集合求和 | ⬜ |
| 14 | [P5743](https://www.luogu.com.cn/problem/P5743) | 【深基7.习8】猴子吃桃 | ⬜ |
| 15 | [P5744](https://www.luogu.com.cn/problem/P5744) | 【深基7.习9】培训 | ⬜ |

---

## 阶段三 · 基础算法

模拟、排序、枚举、递推递归，练手写实现而非调库


### 【算法1-1】模拟与高精度（题单 106，16 题）

<https://www.luogu.com.cn/training/106>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P1042](https://www.luogu.com.cn/problem/P1042) | [NOIP 2003 普及组] 乒乓球 | ⬜ |
| 2 | [P2670](https://www.luogu.com.cn/problem/P2670) | [NOIP 2015 普及组] 扫雷游戏 | ⬜ |
| 3 | [P1563](https://www.luogu.com.cn/problem/P1563) | [NOIP 2016 提高组] 玩具谜题 | ⬜ |
| 4 | [P1601](https://www.luogu.com.cn/problem/P1601) | 高精度加法 | ⬜ |
| 5 | [P1303](https://www.luogu.com.cn/problem/P1303) | A*B Problem | ⬜ |
| 6 | [P1009](https://www.luogu.com.cn/problem/P1009) | [NOIP 1998 普及组] 阶乘之和 | ⬜ |
| 7 | [P4924](https://www.luogu.com.cn/problem/P4924) | [1007] 魔法少女小Scarlet | ⬜ |
| 8 | [P1328](https://www.luogu.com.cn/problem/P1328) | [NOIP 2014 提高组] 生活大爆炸版石头剪刀布 | ⬜ |
| 9 | [P1518](https://www.luogu.com.cn/problem/P1518) | [USACO2.4] 两只塔姆沃斯牛 The Tamworth Two | ⬜ |
| 10 | [P1067](https://www.luogu.com.cn/problem/P1067) | [NOIP 2009 普及组] 多项式输出 | ⬜ |
| 11 | [P1098](https://www.luogu.com.cn/problem/P1098) | [NOIP 2007 提高组] 字符串的展开 | ⬜ |
| 12 | [P1065](https://www.luogu.com.cn/problem/P1065) | [NOIP 2006 提高组] 作业调度方案 | ⬜ |
| 13 | [P1786](https://www.luogu.com.cn/problem/P1786) | 帮贡排序 | ⬜ |
| 14 | [P1591](https://www.luogu.com.cn/problem/P1591) | 阶乘数码 | ⬜ |
| 15 | [P1249](https://www.luogu.com.cn/problem/P1249) | 最大乘积 | ⬜ |
| 16 | [P1045](https://www.luogu.com.cn/problem/P1045) | [NOIP 2003 普及组] 麦森数 | ⬜ |

### 【算法1-2】排序（题单 107，12 题）

<https://www.luogu.com.cn/training/107>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P1271](https://www.luogu.com.cn/problem/P1271) | 【深基9.例1】选举学生会 | ⬜ |
| 2 | [P1177](https://www.luogu.com.cn/problem/P1177) | 【模板】排序 | ⬜ |
| 3 | [P1923](https://www.luogu.com.cn/problem/P1923) | 【深基9.例4】求第 k 小的数 | ⬜ |
| 4 | [P1059](https://www.luogu.com.cn/problem/P1059) | [NOIP 2006 普及组] 明明的随机数 | ⬜ |
| 5 | [P1093](https://www.luogu.com.cn/problem/P1093) | [NOIP 2007 普及组] 奖学金 | ⬜ |
| 6 | [P1781](https://www.luogu.com.cn/problem/P1781) | 宇宙总统 | ⬜ |
| 7 | [P2676](https://www.luogu.com.cn/problem/P2676) | [USACO07DEC] Bookshelf B | ⬜ |
| 8 | [P1116](https://www.luogu.com.cn/problem/P1116) | 车厢重组 | ⬜ |
| 9 | [P1152](https://www.luogu.com.cn/problem/P1152) | 欢乐的跳 | ⬜ |
| 10 | [P1068](https://www.luogu.com.cn/problem/P1068) | [NOIP 2009 普及组] 分数线划定 | ⬜ |
| 11 | [P5143](https://www.luogu.com.cn/problem/P5143) | 攀爬者 | ⬜ |
| 12 | [P1104](https://www.luogu.com.cn/problem/P1104) | 生日 | ⬜ |

### 【算法1-3】暴力枚举（题单 108，14 题）

<https://www.luogu.com.cn/training/108>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P2241](https://www.luogu.com.cn/problem/P2241) | 统计方形（数据加强版） | ⬜ |
| 2 | [P2089](https://www.luogu.com.cn/problem/P2089) | 烤鸡 | ⬜ |
| 3 | [P1618](https://www.luogu.com.cn/problem/P1618) | 三连击（升级版） | ⬜ |
| 4 | [P1036](https://www.luogu.com.cn/problem/P1036) | [NOIP 2002 普及组] 选数 | ⬜ |
| 5 | [P1157](https://www.luogu.com.cn/problem/P1157) | 组合的输出 | ⬜ |
| 6 | [P1706](https://www.luogu.com.cn/problem/P1706) | 全排列问题 | ⬜ |
| 7 | [P1088](https://www.luogu.com.cn/problem/P1088) | [NOIP 2004 普及组] 火星人 | ⬜ |
| 8 | [P3392](https://www.luogu.com.cn/problem/P3392) | 涂条纹 | ⬜ |
| 9 | [P3654](https://www.luogu.com.cn/problem/P3654) | First Step (ファーストステップ) | ⬜ |
| 10 | [P1217](https://www.luogu.com.cn/problem/P1217) | [USACO1.5] Prime Palindromes | ⬜ |
| 11 | [P1149](https://www.luogu.com.cn/problem/P1149) | [NOIP 2008 提高组] 火柴棒等式 | ⬜ |
| 12 | [P3799](https://www.luogu.com.cn/problem/P3799) | 小 Y 拼木棒 | ⬜ |
| 13 | [P2392](https://www.luogu.com.cn/problem/P2392) | kkksc03 考前临时抱佛脚 | ⬜ |
| 14 | [P2036](https://www.luogu.com.cn/problem/P2036) | [COCI 2008/2009 #2] PERKET | ⬜ |

### 【算法1-4】递推与递归（题单 109，15 题）

<https://www.luogu.com.cn/training/109>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P1255](https://www.luogu.com.cn/problem/P1255) | 数楼梯 | ⬜ |
| 2 | [P1002](https://www.luogu.com.cn/problem/P1002) | [NOIP 2002 普及组] 过河卒 | ⬜ |
| 3 | [P1044](https://www.luogu.com.cn/problem/P1044) | [NOIP 2003 普及组] 栈 | ⬜ |
| 4 | [P1028](https://www.luogu.com.cn/problem/P1028) | [NOIP 2001 普及组] 数的计算 | ⬜ |
| 5 | [P1464](https://www.luogu.com.cn/problem/P1464) | [PacNW 1999] Function | ⬜ |
| 6 | [P1928](https://www.luogu.com.cn/problem/P1928) | 外星密码 | ⬜ |
| 7 | [P2437](https://www.luogu.com.cn/problem/P2437) | 蜜蜂路线 | ⬜ |
| 8 | [P1164](https://www.luogu.com.cn/problem/P1164) | 小 A 点菜 | ⬜ |
| 9 | [P1036](https://www.luogu.com.cn/problem/P1036) | [NOIP 2002 普及组] 选数 | ⬜ |
| 10 | [P1990](https://www.luogu.com.cn/problem/P1990) | 覆盖墙壁 | ⬜ |
| 11 | [P3612](https://www.luogu.com.cn/problem/P3612) | [USACO17JAN] Secret Cow Code S | ⬜ |
| 12 | [P1259](https://www.luogu.com.cn/problem/P1259) | 黑白棋子的移动 | ⬜ |
| 13 | [P1010](https://www.luogu.com.cn/problem/P1010) | [NOIP 1998 普及组] 幂次方 | ⬜ |
| 14 | [P1228](https://www.luogu.com.cn/problem/P1228) | 地毯填补问题 | ⬜ |
| 15 | [P1498](https://www.luogu.com.cn/problem/P1498) | 南蛮图腾 | ⬜ |

---

## 阶段四 · 稍难算法

贪心、二分、搜索，开始接触闭包与迭代器风格


### 【算法1-5】贪心（题单 110，14 题）

<https://www.luogu.com.cn/training/110>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P2240](https://www.luogu.com.cn/problem/P2240) | 【深基12.例1】部分背包问题 | ⬜ |
| 2 | [P1223](https://www.luogu.com.cn/problem/P1223) | 排队接水 | ⬜ |
| 3 | [P1803](https://www.luogu.com.cn/problem/P1803) | 凌乱的yyy / 线段覆盖 | ⬜ |
| 4 | [P1090](https://www.luogu.com.cn/problem/P1090) | [NOIP 2004 提高组] 合并果子 | ⬜ |
| 5 | [P3817](https://www.luogu.com.cn/problem/P3817) | 小 A 的糖果 | ⬜ |
| 6 | [P1106](https://www.luogu.com.cn/problem/P1106) | 删数问题 | ⬜ |
| 7 | [P1478](https://www.luogu.com.cn/problem/P1478) | 陶陶摘苹果（升级版） | ⬜ |
| 8 | [P5019](https://www.luogu.com.cn/problem/P5019) | [NOIP 2018 提高组] 铺设道路 | ⬜ |
| 9 | [P1208](https://www.luogu.com.cn/problem/P1208) | [USACO1.3] Mixing Milk | ⬜ |
| 10 | [P1094](https://www.luogu.com.cn/problem/P1094) | [NOIP 2007 普及组] 纪念品分组 | ⬜ |
| 11 | [P4995](https://www.luogu.com.cn/problem/P4995) | 跳跳！ | ⬜ |
| 12 | [P4447](https://www.luogu.com.cn/problem/P4447) | [AHOI2018初中组] 分组 | ⬜ |
| 13 | [P1080](https://www.luogu.com.cn/problem/P1080) | [NOIP 2012 提高组] 国王游戏 | ⬜ |
| 14 | [P1012](https://www.luogu.com.cn/problem/P1012) | [NOIP 1998 提高组] 拼数 | ⬜ |

### 【算法1-6】二分查找与二分答案（题单 111，11 题）

<https://www.luogu.com.cn/training/111>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P2249](https://www.luogu.com.cn/problem/P2249) | 【深基13.例1】查找 | ⬜ |
| 2 | [P1102](https://www.luogu.com.cn/problem/P1102) | A-B 数对 | ⬜ |
| 3 | [P1873](https://www.luogu.com.cn/problem/P1873) | [COCI 2011/2012 #5] EKO / 砍树 | ⬜ |
| 4 | [P1024](https://www.luogu.com.cn/problem/P1024) | [NOIP 2001 提高组] 一元三次方程求解 | ⬜ |
| 5 | [P1678](https://www.luogu.com.cn/problem/P1678) | 烦恼的高考志愿 | ⬜ |
| 6 | [P2440](https://www.luogu.com.cn/problem/P2440) | 木材加工 | ⬜ |
| 7 | [P2678](https://www.luogu.com.cn/problem/P2678) | [NOIP 2015 提高组] 跳石头 | ⬜ |
| 8 | [P3853](https://www.luogu.com.cn/problem/P3853) | [TJOI2007] 路标设置 | ⬜ |
| 9 | [P1182](https://www.luogu.com.cn/problem/P1182) | 数列分段 Section II | ⬜ |
| 10 | [P1163](https://www.luogu.com.cn/problem/P1163) | 银行贷款 | ⬜ |
| 11 | [P3743](https://www.luogu.com.cn/problem/P3743) | 小鸟的设备 | ⬜ |

### 【算法1-7】搜索（题单 112，16 题）

<https://www.luogu.com.cn/training/112>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P1219](https://www.luogu.com.cn/problem/P1219) | [USACO1.5] 八皇后 Checker Challenge | ⬜ |
| 2 | [P2392](https://www.luogu.com.cn/problem/P2392) | kkksc03 考前临时抱佛脚 | ⬜ |
| 3 | [P1443](https://www.luogu.com.cn/problem/P1443) | 马的遍历 | ⬜ |
| 4 | [P1135](https://www.luogu.com.cn/problem/P1135) | 奇怪的电梯 | ⬜ |
| 5 | [P2895](https://www.luogu.com.cn/problem/P2895) | [USACO08FEB] Meteor Shower S | ⬜ |
| 6 | [P1036](https://www.luogu.com.cn/problem/P1036) | [NOIP 2002 普及组] 选数 | ⬜ |
| 7 | [P2036](https://www.luogu.com.cn/problem/P2036) | [COCI 2008/2009 #2] PERKET | ⬜ |
| 8 | [P1433](https://www.luogu.com.cn/problem/P1433) | 吃奶酪 | ⬜ |
| 9 | [P1605](https://www.luogu.com.cn/problem/P1605) | 迷宫 | ⬜ |
| 10 | [P1019](https://www.luogu.com.cn/problem/P1019) | [NOIP 2000 提高组] 单词接龙（疑似错题） | ⬜ |
| 11 | [P1101](https://www.luogu.com.cn/problem/P1101) | 单词方阵 | ⬜ |
| 12 | [P2404](https://www.luogu.com.cn/problem/P2404) | 自然数的拆分问题 | ⬜ |
| 13 | [P1596](https://www.luogu.com.cn/problem/P1596) | [USACO10OCT] Lake Counting S | ⬜ |
| 14 | [P1162](https://www.luogu.com.cn/problem/P1162) | 填涂颜色 | ⬜ |
| 15 | [P1032](https://www.luogu.com.cn/problem/P1032) | [NOIP 2002 提高组] 字串变换（疑似错题） | ⬜ |
| 16 | [P1825](https://www.luogu.com.cn/problem/P1825) | [USACO11OPEN] Corn Maze S | ⬜ |

---

## 阶段五 · 数据结构

线性表、二叉树、集合、图，用 Rust 手写递归类型（Box / Rc / RefCell）


### 【数据结构1-1】线性表（题单 113，10 题）

<https://www.luogu.com.cn/training/113>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P3156](https://www.luogu.com.cn/problem/P3156) | 【深基15.例1】询问学号 | ⬜ |
| 2 | [P3613](https://www.luogu.com.cn/problem/P3613) | 【深基15.例2】寄包柜 | ⬜ |
| 3 | [P1449](https://www.luogu.com.cn/problem/P1449) | 后缀表达式 | ⬜ |
| 4 | [P1996](https://www.luogu.com.cn/problem/P1996) | 约瑟夫问题 | ⬜ |
| 5 | [P1160](https://www.luogu.com.cn/problem/P1160) | 队列安排 | ⬜ |
| 6 | [P1540](https://www.luogu.com.cn/problem/P1540) | [NOIP 2010 提高组] 机器翻译 | ⬜ |
| 7 | [P2058](https://www.luogu.com.cn/problem/P2058) | [NOIP 2016 普及组] 海港 | ⬜ |
| 8 | [P1241](https://www.luogu.com.cn/problem/P1241) | 括号序列 | ⬜ |
| 9 | [P4387](https://www.luogu.com.cn/problem/P4387) | 【深基15.习9】验证栈序列 | ⬜ |
| 10 | [P2234](https://www.luogu.com.cn/problem/P2234) | [HNOI2002] 营业额统计 | ⬜ |

### 【数据结构1-2】二叉树（题单 114，10 题）

<https://www.luogu.com.cn/training/114>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P4715](https://www.luogu.com.cn/problem/P4715) | 【深基16.例1】淘汰赛 | ⬜ |
| 2 | [P4913](https://www.luogu.com.cn/problem/P4913) | 【深基16.例3】二叉树深度 | ⬜ |
| 3 | [P1827](https://www.luogu.com.cn/problem/P1827) | [USACO3.4] 美国血统 American Heritage | ⬜ |
| 4 | [P5076](https://www.luogu.com.cn/problem/P5076) | 【深基16.例7】普通二叉树（简化版） | ⬜ |
| 5 | [P1364](https://www.luogu.com.cn/problem/P1364) | 医院设置 | ⬜ |
| 6 | [P1229](https://www.luogu.com.cn/problem/P1229) | 遍历问题 | ⬜ |
| 7 | [P1305](https://www.luogu.com.cn/problem/P1305) | 新二叉树 | ⬜ |
| 8 | [P1030](https://www.luogu.com.cn/problem/P1030) | [NOIP 2001 普及组] 求先序排列 | ⬜ |
| 9 | [P3884](https://www.luogu.com.cn/problem/P3884) | [JLOI2009] 二叉树问题 | ⬜ |
| 10 | [P1185](https://www.luogu.com.cn/problem/P1185) | 绘制二叉树 | ⬜ |

### 【数据结构1-3】集合（题单 115，15 题）

<https://www.luogu.com.cn/training/115>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P1551](https://www.luogu.com.cn/problem/P1551) | 亲戚 | ⬜ |
| 2 | [P1536](https://www.luogu.com.cn/problem/P1536) | 村村通 | ⬜ |
| 3 | [P3370](https://www.luogu.com.cn/problem/P3370) | 【模板】字符串哈希 | ⬜ |
| 4 | [P3405](https://www.luogu.com.cn/problem/P3405) | [USACO16DEC] Cities and States S | ⬜ |
| 5 | [P5250](https://www.luogu.com.cn/problem/P5250) | 【深基17.例5】木材仓库 | ⬜ |
| 6 | [P5266](https://www.luogu.com.cn/problem/P5266) | 【深基17.例6】学籍管理 | ⬜ |
| 7 | [P1102](https://www.luogu.com.cn/problem/P1102) | A-B 数对 | ⬜ |
| 8 | [P1918](https://www.luogu.com.cn/problem/P1918) | 保龄球 | ⬜ |
| 9 | [P1525](https://www.luogu.com.cn/problem/P1525) | [NOIP 2010 提高组] 关押罪犯 | ⬜ |
| 10 | [P1621](https://www.luogu.com.cn/problem/P1621) | 集合 | ⬜ |
| 11 | [P1892](https://www.luogu.com.cn/problem/P1892) | [BalticOI 2003] 团伙 (Day 2) | ⬜ |
| 12 | [P1955](https://www.luogu.com.cn/problem/P1955) | [NOI2015] 程序自动分析 | ⬜ |
| 13 | [P4305](https://www.luogu.com.cn/problem/P4305) | [JLOI2011] 不重复数字 | ⬜ |
| 14 | [P3879](https://www.luogu.com.cn/problem/P3879) | [TJOI2010] 阅读理解 | ⬜ |
| 15 | [P2814](https://www.luogu.com.cn/problem/P2814) | 家谱 | ⬜ |

### 【数据结构1-4】图的基本应用（题单 116，10 题）

<https://www.luogu.com.cn/training/116>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P5318](https://www.luogu.com.cn/problem/P5318) | 【深基18.例3】查找文献 | ⬜ |
| 2 | [P3916](https://www.luogu.com.cn/problem/P3916) | 图的遍历 | ⬜ |
| 3 | [P1113](https://www.luogu.com.cn/problem/P1113) | [USACO02FEB] 杂务 | ⬜ |
| 4 | [P4017](https://www.luogu.com.cn/problem/P4017) | 最大食物链计数 | ⬜ |
| 5 | [P1807](https://www.luogu.com.cn/problem/P1807) | 最长路 | ⬜ |
| 6 | [P1127](https://www.luogu.com.cn/problem/P1127) | 词链 | ⬜ |
| 7 | [P2853](https://www.luogu.com.cn/problem/P2853) | [USACO06DEC] Cow Picnic S | ⬜ |
| 8 | [P1363](https://www.luogu.com.cn/problem/P1363) | 幻象迷宫 | ⬜ |
| 9 | [P1347](https://www.luogu.com.cn/problem/P1347) | [ECNA 2001] 排序 | ⬜ |
| 10 | [P1983](https://www.luogu.com.cn/problem/P1983) | [NOIP 2013 普及组] 车站分级 | ⬜ |

---

## 阶段六 · 数学

数论与组合基础，练整数边界与溢出处理


### 【数学1】基础数学问题（题单 117，24 题）

<https://www.luogu.com.cn/training/117>

| # | 题号 | 题目 | 状态 |
|---|------|------|------|
| 1 | [P1143](https://www.luogu.com.cn/problem/P1143) | 进制转换 | ⬜ |
| 2 | [P1469](https://www.luogu.com.cn/problem/P1469) | 找筷子 | ⬜ |
| 3 | [P1100](https://www.luogu.com.cn/problem/P1100) | 高低位交换 | ⬜ |
| 4 | [P1017](https://www.luogu.com.cn/problem/P1017) | [NOIP 2000 提高组] 进制转换 | ⬜ |
| 5 | [P1866](https://www.luogu.com.cn/problem/P1866) | 编号 | ⬜ |
| 6 | [P2822](https://www.luogu.com.cn/problem/P2822) | [NOIP 2016 提高组] 组合数问题 | ⬜ |
| 7 | [P2789](https://www.luogu.com.cn/problem/P2789) | 直线交点数 | ⬜ |
| 8 | [P3913](https://www.luogu.com.cn/problem/P3913) | 车的攻击 | ⬜ |
| 9 | [P2638](https://www.luogu.com.cn/problem/P2638) | 安全系统 | ⬜ |
| 10 | [P1246](https://www.luogu.com.cn/problem/P1246) | [ECNA 1995] 编码 | ⬜ |
| 11 | [P2926](https://www.luogu.com.cn/problem/P2926) | [USACO08DEC] Patting Heads S | ⬜ |
| 12 | [P3383](https://www.luogu.com.cn/problem/P3383) | 【模板】线性筛素数 | ⬜ |
| 13 | [P1835](https://www.luogu.com.cn/problem/P1835) | 素数密度 | ⬜ |
| 14 | [P1029](https://www.luogu.com.cn/problem/P1029) | [NOIP 2001 普及组] 最大公约数和最小公倍数问题 | ⬜ |
| 15 | [P1072](https://www.luogu.com.cn/problem/P1072) | [NOIP 2009 提高组] Hankson 的趣味题 | ⬜ |
| 16 | [P1069](https://www.luogu.com.cn/problem/P1069) | [NOIP 2009 普及组] 细胞分裂 | ⬜ |
| 17 | [P1572](https://www.luogu.com.cn/problem/P1572) | 计算分数 | ⬜ |
| 18 | [P4057](https://www.luogu.com.cn/problem/P4057) | [Code+#1] 晨跑 | ⬜ |
| 19 | [P1414](https://www.luogu.com.cn/problem/P1414) | 又是毕业季II | ⬜ |
| 20 | [P2651](https://www.luogu.com.cn/problem/P2651) | 添加括号III | ⬜ |
| 21 | [P2660](https://www.luogu.com.cn/problem/P2660) | zzc 种田 | ⬜ |
| 22 | [P3601](https://www.luogu.com.cn/problem/P3601) | 签到题 | ⬜ |
| 23 | [P1403](https://www.luogu.com.cn/problem/P1403) | [AHOI2005] 约数研究 | ⬜ |
| 24 | [P1593](https://www.luogu.com.cn/problem/P1593) | 因子和 | ⬜ |

---

## Rust 刷题重点提示

| 题单 | Rust 特有坑点 |
|------|--------------|
| 顺序结构 | `println!` 格式化、`stdin().read_line` 读入 |
| 分支结构 | `if` 是表达式、`match` 比 `switch` 强得多 |
| 循环结构 | `for x in 0..n`、`loop` + `break value` 返回值 |
| 数组 | 首选 `Vec<T>`，长度从输入读；注意 `usize` 下标 |
| 字符串 | `String` vs `&str`、`chars()` 而非按字节索引 |
| 函数与结构体 | `struct` + `impl`；首次正面遭遇所有权与借用 |
| 排序 | `sort()` / `sort_by()`，字符串字节序差异 |
| 递推递归 | 递归深度与栈溢出，必要时改迭代 |
| 二叉树 | 递归类型必须用 `Box` / `Option<Box<T>>` |
| 集合/图 | `HashMap` / `HashSet` / `Vec<Vec<usize>>` 邻接表 |

## 输入模板

```rust
use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    // ...
}
```
