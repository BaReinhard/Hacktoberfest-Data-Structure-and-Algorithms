package main

import "fmt"

type queue struct {
    data []interface{}
}

func NewQueue() queue {
    return queue{nil}
}

func (q *queue) Enqueue(value interface{}) {
    q.data = append(q.data, value)
}

func (q *queue) Dequeue() (interface{}) {
    value := q.data[0]
    q.data = q.data[1: len(q.data)]
    return value
}

func main() {
    q := NewQueue()
    q.Enqueue(10)
    q.Enqueue("Hello")
    q.Enqueue(20)
    q.Enqueue(10)
    q.Enqueue("Hello")
    q.Enqueue(20)
    q.Enqueue(10)
    q.Enqueue("Hello")
    q.Enqueue(20)
    q.Enqueue(10)
    q.Enqueue("Hello")
    q.Enqueue(20)
    q.Enqueue(10)
    q.Enqueue("Hello")
    q.Enqueue(20)
    q.Enqueue(10)
    q.Enqueue("Hello")
    q.Enqueue(20)
    fmt.Println(q)
    fmt.Println(q.Dequeue())
    fmt.Println(q.Dequeue())
    fmt.Println(q)
}
