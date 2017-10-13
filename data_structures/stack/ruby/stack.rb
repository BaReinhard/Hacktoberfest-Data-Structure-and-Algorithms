class Stack
    def initialize
        @store = Array.new
    end

    def push(data)
        @store.push(data)
    end

    def pop()
        raise Exception if size == 0
        @store.pop
    end

    def top()
        raise Exception if size == 0
        @store.last
    end

    def size()
        @store.size
    end
end

# Usage
S = Stack.new
S.push(1)
S.push(2)
S.push(3)

puts S.top()
puts S.size()

puts S.pop()
puts S.pop()