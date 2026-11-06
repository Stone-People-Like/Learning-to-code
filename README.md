

# Stone 的 Go 学习记录

> 陆云清的个人 Go 学习分支 — 用洛谷刷题快速上手 Go

## 关于我

我是陆云清（Stone），正在学习 Go 编程。学习方式是**通过洛谷题单刷题**，在做题中逐步掌握 Go 的语法、切片、接口与并发模型。

已经刷完的题会标记状态，卡住的地方整理成笔记，方便回头复习。

## 学习路线

完整路线见 [`Go/洛谷刷题/README.md`](Go/洛谷刷题/README.md)，共 18 个题单 / 271 题，按 Go 学习曲线分为六个阶段：

| 阶段 | 内容 | 题单 | 题数 |
|------|------|------|------|
| 一 · 语法入门 | 输入输出、控制流 | 100–102 | 54 |
| 二 · 数据组织 | slice / string / struct | 103–105 | 50 |
| 三 · 基础算法 | 模拟、排序、枚举、递推 | 106–109 | 57 |
| 四 · 稍难算法 | 贪心、二分、搜索 | 110–112 | 41 |
| 五 · 数据结构 | 线性表、树、集合、图 | 113–116 | 45 |
| 六 · 数学 | 数论与整数边界 | 117 | 24 |

## 目录结构

```
Stone-code-Go/
├── README.md                    # 本文件
├── luogu-go/                    # 刷题工作区（每题一个目录）
│   ├── go.mod                   # module luogu-go
│   ├── README.md                # 运行方式说明
│   ├── B2002/main.go            # Hello,World!（完整示例）
│   ├── P1001/main.go            # A+B Problem（完整示例）
│   └── ...                      # 其余 260 道题的 main.go 骨架
└── Go/
    └── 洛谷刷题/                # 题单与进度跟踪
        ├── README.md            # 完整路线说明
        ├── 01_语法入门/
        │   ├── 100_入门1顺序结构/
        │   └── ...
        └── 06_数学/
```

## 刷题流程

```bash
cd luogu-go

# 1. 打开对应题目文件
#    luogu-go/P1001/main.go

# 2. 本地测试
go run ./P1001 < in.txt

# 3. 检查编译
go vet ./P1001

# 4. 提交洛谷，通过后在题单 README 里把 ⬜ 改成 ✅
```

输入输出模板（洛谷数据量大，用 `bufio` 避免超时）：

```go
import (
    "bufio"
    "fmt"
    "os"
)

in := bufio.NewReader(os.Stdin)
out := bufio.NewWriter(os.Stdout)
defer out.Flush()

var n int
fmt.Fscan(in, &n)
```

## 开发环境

- **版本**: Go 1.26.5（`/usr/local/go/bin/go`）
- **模块代理**: `https://goproxy.cn,direct`
- **校验数据库**: `sum.golang.google.cn`
- **IDE**: 任意支持 Go 的编辑器（Goland / VSCode + gopls）

常用命令：

```bash
go version                     # 查看版本
go run ./<题号>                # 运行某题
go vet ./<题号>                # 检查编译
go build -o /tmp/p ./<题号>    # 编译成可执行文件
go mod tidy                    # 整理依赖
gofmt -w .                     # 格式化
```

## 学习资源

### 官方文档
- [Go 官方文档](https://go.dev/doc/)
- [Go 语言之旅（中文）](https://tour.go-zh.org/)
- [Effective Go](https://go.dev/doc/effective_go)
- [Go by Example](https://gobyexample.com/)

### 题目来源
- [洛谷题单列表](https://www.luogu.com.cn/training/list)
- [洛谷题库](https://www.luogu.com.cn/problem/list)

---

公共学习资料请查看 [`main` 分支](https://github.com/Stone-People-Like/Learning-to-code/tree/main)