// Created on Oct 615:19 2018
// author: grendach@gmail.com
// Tower of Hanoi algorithm implemented in Go

package main

import (
	"fmt"
)

type solver interface {
	play(int)
}

//epty interface that satisfy solver interface
type towers struct {
}

//play method required to implement solver type
func (t *towers) play(n int) {
	t.moveN(n, 1, 2, 3)
}

//recurcive algorithm
func (t *towers) moveN(n, from, to, via int) {
	if n > 0 {
		t.moveN(n-1, from, via, to)
		t.moveM(from, to)
		t.moveN(n-1, via, to, from)
	}
}

func (t *towers) moveM(from, to int) {
	fmt.Println("Move disk from rod", from, "to rod", to)
}

func main() {
	var t solver
	t = new(towers) //type towers must satisfy solver interface
	t.play(4)
}
