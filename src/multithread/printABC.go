package main

import (
	"fmt"
	"sync"
)

// 三个协程交替打印ABC 十遍
func main() {
	aChan := make(chan struct{})
	bChan := make(chan struct{})
	cChan := make(chan struct{})

	count := 10
	var wg sync.WaitGroup
	wg.Add(3)
	go func() {
		defer wg.Done()
		for i := 0; i < count; i++ {
			<-aChan
			fmt.Println("A")
			bChan <- struct{}{}
		}
	}()

	go func() {
		defer wg.Done()
		for i := 0; i < count; i++ {
			<-bChan
			fmt.Println("B")
			cChan <- struct{}{}
		}
	}()

	go func() {
		defer wg.Done()
		for i := 0; i < count; i++ {
			<-cChan
			fmt.Println("C")
			// 死锁的坑，最后一个的循环已退出
			if i == count-1 {
				return
			}
			aChan <- struct{}{}
		}
	}()

	aChan <- struct{}{}
	wg.Wait()
}
