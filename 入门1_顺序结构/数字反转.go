package main

import "fmt"

func main() {
	var s string
	fmt.Scan(&s)

	b := []byte(s)
	for i, j := 0, len(b)-1; i < j; i, j = i+1, j-1 {
		b[i], b[j] = b[j], b[i]
	}
	fmt.Println(string(b))
}
