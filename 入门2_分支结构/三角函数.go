package main

import "fmt"

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)
	min := a
	max := a
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
	convention := gcd(min, max)
	fmt.Printf("%d/%d", min/convention, max/convention)
}
