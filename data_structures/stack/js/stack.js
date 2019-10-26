class Stack {
  constructor () {
    this.data = []
    this.max = -1
  }
  pop () {
    if (this.max === -1)
      throw new Exception("Stack is empty");

    this.max--
  }

  push (data) {
    this.max++
    this.data.push(data)
  }

  top () {
    return this.data[this.max]
  }
}

// usage
const stack = new Stack()
stack.push("a")
stack.push("b")

console.log(stack.top())

stack.pop()

console.log(stack.top())

