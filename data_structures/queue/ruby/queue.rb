class Queue
    def initialize
        @store = Array.new
    end

    def enqueue(data)
        @store.push(data)
    end

    def dequeue()
        raise Exception if size == 0
        @store.shift
    end

    def front()
        raise Exception if size == 0
        @store.first
    end

    def back()
        @store.last
    end

    def size()
        @store.size
    end
end

# Usage
Q = Queue.new
Q.enqueue(1)
Q.enqueue(2)
Q.enqueue(3)

puts Q.front()
puts Q.back()

puts Q.dequeue()
puts Q.dequeue()