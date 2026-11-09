package main

import "fmt"

func main() {
	var a, b, c float64
	fmt.Scan(&a, &b, &c)
	fmt.Print(a*0.2 + b*0.3 + c*0.5)
}
