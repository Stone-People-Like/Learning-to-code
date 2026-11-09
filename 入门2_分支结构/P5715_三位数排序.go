package main

import "fmt"

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)
	max := a
	min := a
	if max < b {
		max = b
	}
	if max < c {
		max = c
	}
	if min > b {
		min = b
	}
	if min > c {
		min = c
	}
	fmt.Print(min, a+b+c-max-min, max)

}
