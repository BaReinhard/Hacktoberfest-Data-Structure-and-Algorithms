package main

import (
	"reflect"
	"testing"
)

func TestMergeSort(t *testing.T) {
	cases := []struct {
		sample, expected []int64
	}{
		{
			[]int64{3, 1, 2},
			[]int64{1, 2, 3},
		},
		{
			[]int64{5, 6, 7, 8, 1, 2, 3, 4},
			[]int64{1, 2, 3, 4, 5, 6, 7, 8},
		},
		{
			[]int64{2012, 5023, 456, 10, 56, 123},
			[]int64{10, 56, 123, 456, 2012, 5023},
		},
		{
			[]int64{},
			[]int64{},
		},
	}
	for _, c := range cases {
		result := MergeSort(c.sample)
		if !reflect.DeepEqual(result, c.expected) {
			t.Fail()
			if testing.Verbose() {
				t.Logf("got: %v\n expected: %v", result, c.expected)
			}
		}
	}
}
