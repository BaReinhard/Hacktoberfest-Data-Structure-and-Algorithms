package main

import "fmt"

// Basic implementation of recursive merge sort

func rec_m_sort(arr []int) []int {
	if len(arr) > 1 {
		m := int(len(arr) / 2)
		arr1 := rec_m_sort(arr[:m])
		arr2 := rec_m_sort(arr[m:])
		i0 := 0
		i1 := 0
		i2 := 0
		// merge
		for i0 < len(arr) {
			if i1 < len(arr1) && i2 < len(arr2) {
				// both sub arrays
				if arr1[i1] < arr2[i2] {
					arr[i0] = arr1[i1]
					i1++
				} else {
					arr[i0] = arr2[i2]
					i2++
				}
			} else if i1 < len(arr1) {
				// only first sub array
				arr[i0] = arr1[i1]
				i1++
			} else {
				// only second sub array
				arr[i0] = arr2[i2]
				i2++
			}
			i0++
		}
	}
	// build in depth copy
	ret := make([]int, len(arr))
	for i := range arr {
		ret[i] = arr[i]
		i++
	}
	return ret
}

func main() {

	arr := []int{9, 2, 1, 0, 1, 2, 3, 8}
	arr = rec_m_sort(arr)
	fmt.Println(arr)
}
