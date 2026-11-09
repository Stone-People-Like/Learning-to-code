package main

import "fmt"

func main() {
	var m, h float64
	fmt.Scan(&m, &h)
	BMI := m / (h * h)
	if BMI < 18.5 {
		fmt.Print("Underweight")
	} else if BMI < 24 {
		fmt.Print("Normal")
	} else {
		fmt.Printf("%.4f\n", BMI)
		fmt.Print("Overweight")

	}
}
