package main

type stack struct {
	data []interface{}
}

func (s *stack) Push(value interface{}) {
	s.data = append(s.data, value)
}

func (s *stack) Pop() interface{} {
	//get last item
	value := s.data[len(s.data)-1]
	//shrink array
	s.data = s.data[0 : len(s.data)-1]

	return value
}
