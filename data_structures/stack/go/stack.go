package stack

type Item interface{}

// Stack of items (implemented as array)
type Stack struct {
    Items []Item
}

// New creates a new Stack
func (s *Stack) New() *Stack {
    s.Items = []Item{}
    return s
}

// Push adds an item to the top of the stack
func (s *Stack) Push(i Item) {
    s.Items = append(s.Items, i)
}

// Pop removes an item from the top of the stack
func (s *Stack) Pop() *Item {
    item := s.Items[len(s.Items) - 1]
    s.Items = s.Items[0 : len(s.Items) - 1]
    return &item
}
