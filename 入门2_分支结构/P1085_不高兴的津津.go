package main

import "fmt"

func main() {
	maxTime := 8 // 只有超过 8 小时才算不高兴
	ansDay := 0  // 0 表示不会不高兴

	for i := 0; i < 7; i++ {
		var school, mom int
		fmt.Scan(&school, &mom)

		sum := school + mom
		if sum > maxTime {
			maxTime = sum
			ansDay = i + 1 // 第 i 天对应星期 i+1
		}
	}

	fmt.Println(ansDay)
}
