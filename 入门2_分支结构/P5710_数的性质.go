package main

import (
	"fmt"
)

func main() {
	var x int
	fmt.Scan(&x)
	number := 0

	if x%2 == 0 {
		number++
	}
	if x <= 12 && 4 <= x {
		number++
	}

	if number == 2 {
		fmt.Print(1, " ")
	} else {
		fmt.Print(0, " ")
	}
	if number != 0 {
		fmt.Print(1, " ")
	} else {
		fmt.Print(0, " ")
	}
	if number == 1 {
		fmt.Print(1, " ")
	} else {
		fmt.Print(0, " ")
	}

	if number == 0 {
		fmt.Print(1, " ")
	} else {
		fmt.Print(0, " ")
	}
}
