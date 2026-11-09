package main

import "fmt"

func main() {
	var t, n float64
	fmt.Scan(&t, &n)
	fmt.Printf("%.3f", t/n)
	fmt.Println()
	fmt.Print(n * 2)
}
