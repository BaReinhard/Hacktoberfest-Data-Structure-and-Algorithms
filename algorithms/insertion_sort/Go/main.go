// Created on Oct 2 13:09 2018
// author: grendach@gmail.com
// Just a simple implementation of the string and integer sorting
// install golang and run "go run main.go" command

package main

import (
	"fmt"
	"sort"
)

func main() {
	strs := []string{"z", "a", "c", "t", "b", "w", "d"}
	fmt.Println("Unsorted strings: ", strs)
	sort.Strings(strs)
	fmt.Println("Sorted strings: ", strs)

	ints := []int{5, 4, 87, 45, 2, 4, 1, 3}
	fmt.Println("Unsorted ints: ", ints)
	sort.Ints(ints)
	fmt.Println("Sorted ints: ", ints)
}
