package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	localTime := n * 5
	luoguTime := 11 + n*3
	if localTime < luoguTime {
		fmt.Print("Local")
	} else {
		fmt.Print("Luogu")
	}
}
