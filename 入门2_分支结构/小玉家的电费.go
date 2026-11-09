package main

import "fmt"

func main() {
	var electricity float64
	fmt.Scan(&electricity)
	//basic_Perice :=
	if electricity <= 150 {
		fmt.Printf("%.1f", electricity*0.4463)
	} else if electricity <= 400 {
		unnecessary_Electricity := electricity - 150
		fmt.Printf("%.1f", unnecessary_Electricity*0.4663+150*0.4463)
	} else {
		fmt.Printf("%.1f", 150*0.4463+250*0.4663+(electricity-400)*0.5663)
	}
}
