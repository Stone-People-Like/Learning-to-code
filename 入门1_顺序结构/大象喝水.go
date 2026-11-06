package main

import (
	"fmt"
	"math"
)

func main() {
	var h, r float64
	fmt.Scan(&h, &r)
	const Pi = 3.14
	area := Pi * r * r //水杯的底面积
	volume := area * h
	fmt.Print(math.Ceil(20000 / volume))
}
