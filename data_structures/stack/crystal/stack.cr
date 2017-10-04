class Stack(T)
  @size : Int32

  def initialize(@stack : Array(T))
    @size = @stack.size
  end

  # Returns size (Implicit return)
  def push(item : T)
    @stack << item
    @size += 1
  end

  # Returns size (Implicit return)
  def pop()
    @stack.pop
    @size -= 1
  end

  def peek()
    @stack.last
  end

  def size()
    @size
  end
end

# Union together Types you might need since crystal is type-checked at compile time
# You'll get an error if you try and push a type that isn't in the union
stack = Stack.new([] of Int32|String)

puts stack.size()         # ==> 0
stack.push(30)            # ==> [30]
stack.push("Hello")       # ==> [30, "hello"]
stack.pop()               # ==> 1
puts stack.peek()         # ==> 30

