package main

import "fmt"

func main() {
	var x int
	fmt.Scan(&x)
	if x > 1 {
		fmt.Printf("Today, I ate %d apples.", x)
	} else {
		fmt.Printf("Today, I ate %d apple.", x)
	}
}
