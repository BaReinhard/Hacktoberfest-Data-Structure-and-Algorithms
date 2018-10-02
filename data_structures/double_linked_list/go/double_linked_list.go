package main

import "fmt"

type elem struct {
	value int
	prev  *elem
	next  *elem
}

type list struct {
	head     *elem
	tail     *elem
	size     int
}

func newList() list {
	return list{head: nil, tail: nil, size: 0}
}

func newElem(v int) *elem {
	return &elem{prev: nil, next: nil, value: v}
}

func (l *list) appendAfter(v int) {
	e := newElem(v)
	if l.size == 0 {
		l.head = e
		l.tail = e
	} else {
		e.prev = l.tail
		e.next = l.tail.next
		l.tail.next = e
		l.tail = e
	}
	l.size++
}

func (l *list) appendBefore(v int) {
	e := newElem(v)
	if l.size == 0 {
		l.head = e
		l.tail = e
	} else {
		e.prev = l.head.prev
		e.next = l.head
		l.head.prev = e
		l.head = e
	}
	l.size++
}

func (l *list) removeHead() {
	if l.size > 0 {
		if l.size > 1{
			l.head.next.prev = l.head.prev
		}
		l.head = l.head.next
		l.size--
	}
}

func (l *list) removeTail() {
	if l.size > 0 {
		if l.size > 1 {
			l.tail.prev.next = l.tail.next
		}
		l.tail = l.tail.prev
		l.size--
	}
}

func (l *list) toArray() []int{
	ret := make([]int, l.size)
	i := 0
	current := l.head
	for i < l.size{
		ret[i] = current.value
		current = current.next
		i++
	}
	return ret
}

func (l *list) toReverseArray() []int{
	ret := make([]int, l.size)
	i := 0
	current := l.tail
	for i < l.size{
		ret[i] = current.value
		current = current.prev
		i++
	}
	return ret
}

func main() {
	l := newList()
	// insert
	l.appendAfter(1)
	l.appendAfter(2)
	l.appendAfter(3)
	l.appendBefore(4)
	l.appendBefore(5)
	l.appendBefore(6)
	fmt.Println("As array : ", l.toArray())
	fmt.Println("As reverse array : ", l.toReverseArray())
	// remove
	l.removeHead()
	l.removeHead()
	l.removeHead()
	fmt.Println("As array (after head remove) : ", l.toArray())
	l.appendBefore(4)
	l.appendBefore(5)
	l.appendBefore(6)
	l.removeTail()
	l.removeTail()
	l.removeTail()
	fmt.Println("As array (after tail remove) : ", l.toArray())
}