package main

import "fmt"

type Node struct {
	Value int
	Left  *Node
	Right *Node
}

type BinarySearchTree struct {
	Root *Node
}

func (n *Node) Insert(v int) {
	if v <= n.Value {
		if n.Left == nil {
			n.Left = &Node{v, nil, nil}
			return
		}
		n.Left.Insert(v)
		return
	}

	if n.Right == nil {
		n.Right = &Node{v, nil, nil}
		return
	}

	n.Right.Insert(v)
}

func (b *BinarySearchTree) Insert(v int) {
	if b.Root != nil {
		b.Root.Insert(v)
		return
	}

	b.Root = &Node{v, nil, nil}
}

func PrintTreeInOrder(n *Node) {
	if n == nil {
		return
	}

	if n.Left != nil {
		PrintTreeInOrder(n.Left)
	}

	fmt.Println(n.Value)

	if n.Right != nil {
		PrintTreeInOrder(n.Right)
	}
}

func main() {
	var btree BinarySearchTree
	btree.Insert(400)
	btree.Insert(100)
	btree.Insert(80)
	btree.Insert(120)
	btree.Insert(180)
	btree.Insert(60)
	btree.Insert(40)
	btree.Insert(200)

	PrintTreeInOrder(btree.Root)
}
