package main

import "fmt"

type Node struct {
	Value interface{}
	next  *Node
}

func (n *Node) Next() *Node {
	return n.next
}

type LinkedList struct {
	first *Node
	last  *Node
}

func (l *LinkedList) Add(v interface{}) {
	n := new(Node)
	n.Value = v
	if l.first == nil {
		l.first = n
		l.last = n
	} else {
		l.last.next = n
		l.last = n
	}
}

func (l *LinkedList) First() *Node {
	return l.first
}

func (l *LinkedList) ToString() string {
	str := ""
	if l.first != nil {
		n := l.first
		str += n.Value.(string)
		for n.next != nil {
			str += "," + n.next.Value.(string)
			n = n.next
		}
	}
	return str
}

func main() {
	list := new(LinkedList)
	list.Add("a")
	list.Add("b")
	list.Add("c")

	fmt.Printf(list.ToString() + "\n")
}
