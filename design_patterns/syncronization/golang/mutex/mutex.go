package main

import (
	"fmt"
	"sync"
)

func TestNoMutex() {
	a := 0
	intchan := make(chan int)

	// fill channel with integers
	go func() {
		for ii := 0; ii <= 100; ii++ {
			intchan <- ii
		}
		close(intchan)
	}()

	var wg sync.WaitGroup

	// This does not guarantee the result to be 5050
	for ii := 0; ii < 5; ii++ {
		wg.Add(1)
		go func(inc *int) {
			defer wg.Done()
			for num := range intchan {
				*inc += num
			}
		}(&a)
	}

	wg.Wait()

	fmt.Println(a)
}

func TestWithMutex() {
	a := 0
	intchan := make(chan int)
	mtx := make(chan int, 1)

	mtx <- 1
	// fill channel with integers
	go func() {
		for ii := 0; ii <= 100; ii++ {
			intchan <- ii
		}
		close(intchan)
	}()

	var wg sync.WaitGroup

	for ii := 0; ii < 5; ii++ {
		wg.Add(1)
		go func(inc *int) {
			defer wg.Done()
			for num := range intchan {
				// Adding this token as a mutex makes sure there are no race conditions
				<-mtx
				*inc += num
				mtx <- 1
			}
		}(&a)
	}

	wg.Wait()

	fmt.Println(a)
}

func main() {
	TestNoMutex()
	TestWithMutex()
}
