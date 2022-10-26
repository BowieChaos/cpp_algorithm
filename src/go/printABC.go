package main

import (
	"fmt"
	"sync"
	"time"
)

var ch1 = make(chan int)
var ch2 = make(chan int)
var ch3 = make(chan int)
var closech = make(chan int)
var wg sync.WaitGroup
var count = 0

func PrintA() {
	defer wg.Done()
	for {
		select {
		case <-ch1:
			fmt.Println("A")
			ch2 <- 1
		}
	}
}

func PrintB() {
	defer wg.Done()
	for {
		select {
		case <-ch2:
			fmt.Println("B")
			ch3 <- 1
		case <-time.After(time.Second * 5):
			return
		}
	}
}
func PrintC() {
	defer wg.Done()

	for {
		select {
		case <-ch3:
			fmt.Println("C")
			ch1 <- 1
		case <-time.After(time.Second * 5):
			return
		}
	}
}
func main() {
	wg.Add(3)
	go PrintA()
	go PrintB()
	go PrintC()
	ch1 <- 1
	wg.Wait()

}
