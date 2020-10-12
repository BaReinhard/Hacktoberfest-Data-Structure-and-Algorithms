package main

import "fmt"

func main() {

	arr := [12]int{5, 3, 2, 22, 1, 5, 3, 2, 1, 55, 123, 2}

	// counting sort
	max := 0

	for i := 0; i < len(arr); i++ {
		if arr[i] > max {
			max = arr[i]
		}
	}

	countingLib := make([]int, max+1)

	for i := 0; i < len(arr); i++ {
		countingLib[arr[i]]++
	}

	arrNew := [len(arr)]int{}

	count := 0

	for i := 0; i < len(countingLib); i++ {

		if countingLib[i] != 0 {
			arrNew[count] = i
			countingLib[i]--
			count++
			i--
		}
	}

	arr = arrNew
	fmt.Println(arr)
}
