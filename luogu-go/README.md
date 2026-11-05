# 洛谷刷题工作区（Go）

每题一个独立目录，目录名就是题号，跑起来只需要一条 `go run`。

## 常用命令

```bash
cd luogu-go

# 运行某题（从文件读输入）
go run ./P1001 < in.txt

# 手动输入后 Ctrl-D 结束
go run ./P1001

# 只检查编译
go vet ./P1001

# 编译成可执行文件
go build -o /tmp/p1001 ./P1001
```

## 输入输出

洛谷的输入输出量大，用 `fmt.Scan` 容易超时，推荐 `bufio`：

```go
import (
    "bufio"
    "fmt"
    "os"
)

in := bufio.NewReader(os.Stdin)
out := bufio.NewWriter(os.Stdout)
defer out.Flush()

// 读整数（自动跳过空白）
var n int
fmt.Fscan(in, &n)

// 一次读一行（保留空格）
line, _ := in.ReadString('\n')
```

## 新建一道题

```bash
cd luogu-go
mkdir P1008 && vi P1008/main.go
```

文件第一行必须是 `package main`，并且要有 `func main()`。

## 目录说明

题目分类目录在 `../Go/洛谷刷题/`，每题单有一个 `README.md` 记录题单与进度。