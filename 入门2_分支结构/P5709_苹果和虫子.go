package main

import "fmt"

func main() {
	var m, t, s int
	fmt.Scan(&m, &t, &s)

	if t == 0 {
		// 题目中 s >= 1，0 分钟吃完一个，说明已经全部被吃/正在吃
		fmt.Println(0)
		return
	}

	eaten := (s + t - 1) / t // 等价于 ceil(s / t)
	ans := m - eaten
	if ans < 0 {
		ans = 0
	}

	fmt.Println(ans)
}
