package main

import "fmt"

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	// 三数排序：a <= b <= c
	if a > b {
		a, b = b, a
	}
	if b > c {
		b, c = c, b
	}
	if a > b {
		a, b = b, a
	}

	// 1. 能不能组成三角形
	if a+b <= c {
		fmt.Println("Not triangle")
		return // 不能组成三角形，后面的分类都不输出
	}

	// 2. 按角分类
	if a*a+b*b == c*c {
		fmt.Println("Right triangle")
	} else if a*a+b*b > c*c {
		fmt.Println("Acute triangle")
	} else {
		fmt.Println("Obtuse triangle")
	}

	// 3. 等腰、等边
	if a == b || b == c {
		fmt.Println("Isosceles triangle")
	}
	if a == b && b == c {
		fmt.Println("Equilateral triangle")
	}
}
