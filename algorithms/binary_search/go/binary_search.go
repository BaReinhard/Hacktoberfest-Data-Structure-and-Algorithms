package main

import "fmt"

// Basic implementations of the binary search

// Recursive
func rec_b_search(v int, arr []int, b int, e int) int {
	m := int((b+e)/2)
	if b > e{
		return -1
	} else if v == arr[m]{
		return m
	} else if v > arr[m]{
		return rec_b_search(v, arr, m+1, e)
	} else if v < arr[m]{
		return rec_b_search(v, arr, b, m-1)
	}
	return -1
}

// Iterative
func iter_b_search(v int, arr []int, b int, e int) int {
	for b <= e {
		m := int((b+e)/2)
		if v == arr[m]{
			return m
		} else if v > arr[m]{
			b = m+1
		} else if v < arr[m]{
			e = m-1
		}
	}
	return -1
}

func main() {
	arr := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	// test with value in array
	fmt.Println(rec_b_search(3, arr, 0, len(arr)-1))
	fmt.Println(iter_b_search(3, arr, 0, len(arr)-1))
	// test with value not in array
	fmt.Println(rec_b_search(12, arr, 0, len(arr)-1))
	fmt.Println(iter_b_search(12, arr, 0, len(arr)-1))
}