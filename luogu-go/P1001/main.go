package main

// P1001 - A+B Problem
// https://www.luogu.com.cn/problem/P1001

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	var a, b int64
	fmt.Fscan(in, &a, &b)
	fmt.Println(a + b)
}
