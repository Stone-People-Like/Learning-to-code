package main

import (
	"fmt"
)

func main() {
	var a, b float64
	fmt.Scan(&a, &b)
	realNumber := a + b/10
	fmt.Print(int(realNumber / 1.9))
}
