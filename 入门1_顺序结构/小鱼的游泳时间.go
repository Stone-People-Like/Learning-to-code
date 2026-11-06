package main

import "fmt"

func main() {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)
	if b == d {
		fmt.Print(c-a, 0)
	} else if d > b {
		fmt.Print(c-a, d-b)
	} else {
		fmt.Print(c-a-1, d-b+60)
	}
}
