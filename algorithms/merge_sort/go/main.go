package main

func main() {
}

// MergeSort uses merge sort
// algorithm to sort an array.
func MergeSort(array []int64) []int64 {
	m := len(array)
	if m <= 1 {
		return array
	}
	indexHalf := (m / 2)
	// len(left) <= len(right) <= len(left) + 1
	left := array[:indexHalf]
	right := array[indexHalf:]
	left = MergeSort(left)
	right = MergeSort(right)
	return merge(left, right)
}

func merge(left, right []int64) []int64 {
	totLen := len(left) + len(right)
	sorted := make([]int64, 0, totLen)
	for i := 0; i < totLen; i++ {
		if len(left) == 0 {
			sorted = append(sorted, right...)
			break
		}
		if len(right) == 0 {
			sorted = append(sorted, left...)
			break
		}
		if left[0] <= right[0] {
			sorted = append(sorted, left[0])
			if len(left) == 1 {
				left = nil
				continue
			}
			left = left[1:]
		} else {
			sorted = append(sorted, right[0])
			if len(right) == 1 {
				right = nil
				continue
			}
			right = right[1:]
		}
	}
	return sorted
}
