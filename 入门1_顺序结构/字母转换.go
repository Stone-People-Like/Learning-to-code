package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scanln(&s)
	if "a" <= s && s <= "z" {
		fmt.Print(strings.ToUpper(s))
	} else {
		fmt.Print(strings.ToLower(s))
	}
}
