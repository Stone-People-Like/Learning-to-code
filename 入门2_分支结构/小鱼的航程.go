package main

import "fmt"

func main() {
	var x, n int
	fmt.Scan(&x, &n)
	day := 0
	sum := 0
	for i := x; i < n+x; i++ {
		sum++
		if i%7 == 0 || i%7 == 6 {
			day++
		}
	}
	fmt.Print(250 * (sum - day))
}
