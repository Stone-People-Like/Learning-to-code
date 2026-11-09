package main

import (
	"fmt"
	"sort"
)

func main() {
	var needNumber int
	fmt.Scan(&needNumber)

	minList := []int{}
	for i := 0; i < 3; i++ {
		var suitQuantity, suitPrice int
		fmt.Scan(&suitQuantity, &suitPrice)

		// 向上取整：至少需要买几份
		suit := (needNumber + suitQuantity - 1) / suitQuantity
		finallyPrice := suitPrice * suit
		minList = append(minList, finallyPrice)
	}

	sort.Ints(minList)
	fmt.Println(minList[0])
}
