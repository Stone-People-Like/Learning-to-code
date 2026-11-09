package main

import (
	"fmt"
	"math"
)

func main() {
	var a int
	fmt.Scan(&a)
	switch a {
	case 1:
		fmt.Println("I love Luogu!")
	case 2:
		fmt.Print(2+4, 10-6)
	case 3:
		fmt.Println(14 / 4)
		fmt.Println(14 / 4 * 4)
		fmt.Println(2)
	case 4:
		fmt.Printf("%.6f", 500/3)
	case 5:
	case 6:
		fmt.Print(math.Sqrt(81 + 36))

	}
}
