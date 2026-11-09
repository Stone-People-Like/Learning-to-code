package main

import "fmt"

// 判断是否闰年
func isLeap(year int) bool {
	if year%400 == 0 {
		return true
	}
	if year%4 == 0 && year%100 != 0 {
		return true
	}
	return false
}

// 判断是否 31 天的月份
func is31(month int) bool {
	Month31 := []int{1, 3, 5, 7, 8, 10, 12}
	for _, i := range Month31 {
		if month == i {
			return true
		}
	}
	return false // 循环结束后还没找到，才返回 false
}

func main() {
	var year, month int
	fmt.Scan(&year, &month)

	var days int
	if month == 2 {
		if isLeap(year) {
			days = 29
		} else {
			days = 28
		}
	} else if is31(month) {
		days = 31
	} else {
		days = 30
	}

	fmt.Println(days)
}
