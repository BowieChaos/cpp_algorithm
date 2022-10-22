package main

import "fmt"

type MyInt int8

// 注意看~int8
func add[T int64 | float64 | ~int8](a, b T) T {
	return a + b
}

func Generate(c chan<- int) {
	for i := 2; ; i++ {
		c <- i
	}
}

func Filter(in <-chan int, out chan<- int, prime int) {
	for {
		i := <-in
		if i%prime != 0 {
			out <- i
		}

	}
}

func main() {
	// 限制底层数据类型
	//fmt.Println("MyInt 1 + 2 = ", add[MyInt](1, 2))
	ch := make(chan int)
	go Generate(ch)
	for i := 0; i < 1000; i++ {
		prime := <-ch
		fmt.Println(prime)
		ch1 := make(chan int)
		go Filter(ch, ch1, prime)
		ch = ch1
	}

}
