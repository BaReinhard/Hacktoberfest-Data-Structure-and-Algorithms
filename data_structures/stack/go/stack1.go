package main

import (
	"errors"
	"fmt"
)

type stackElement struct {
	val interface{}
}

type stack struct {
	Elements []stackElement
}

func (s *stack) push(elem stackElement) {
	s.Elements = append(s.Elements, elem)
}

func (s *stack) pop() (stackElement, error) {
	var poppedElem stackElement

	if len(s.Elements) > 0 {
		stackLength := len(s.Elements)
		poppedElem = s.Elements[stackLength-1]
		s.Elements = s.Elements[:stackLength-1]
		return poppedElem, nil
	}
	return poppedElem, errors.New("Can't pop element from empty stack!")
}

func (s *stack) hasMoreElements() bool {
	return len(s.Elements) > 0
}

func main() {
	myStack := stack{}
	myStack.push(stackElement{val: "Go"})
	myStack.push(stackElement{val: "in"})
	myStack.push(stackElement{val: "stack"})
	myStack.push(stackElement{val: "a"})
	myStack.push(stackElement{val: "is"})
	myStack.push(stackElement{val: "This"})

	for myStack.hasMoreElements() {
		elem, err := myStack.pop()
		if err == nil {
			fmt.Println(elem.val)
		} else {
			panic(err.Error())
		}
	}
}
