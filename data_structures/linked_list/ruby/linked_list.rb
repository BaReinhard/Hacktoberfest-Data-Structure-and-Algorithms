class Node
    attr_writer :next
    attr_reader :next, :data

    def initialize(data, next_node = nil)
        @data = data
        @next = next_node
    end
end

class LinkedList
    def initialize
        @head = nil
        @tail = @head
    end

    def insertFront(data)
        node = Node.new(data, @head)
        @tail = node if @tail == nil
        @head = node
    end

    def insertBack(data)
        node = Node.new(data)
        @head = node if @head == nil
        @tail.next = node if @tail != nil
        @tail = node
    end

    def find(data)
        current = @head
        while current != nil do
            return current if data == current.data
            current = current.next
        end
        return nil
    end

    def remove(node)
        prev = nil
        current = @head

        while current != nil do
            if node.equal? current
                if current == @head
                    @head = @head.next
                elsif current == @tail
                    @tail = prev
                    prev.next = nil
                else
                    prev.next = current.next
                end
                break
            end
            prev = current
            current = current.next
        end
    end

    def iterate
        current = @head
        while current != nil do
            yield current.data
            current = current.next
        end
    end
end

# Usage
L = LinkedList.new
L.insertBack(3)
L.insertBack(4)
L.insertFront(2)
L.insertFront(1)

# 1 2 3 4
L.iterate { |data| puts(data) }

node_2 = L.find(4)
L.remove(node_2)

# 1 3 4
L.iterate { |data| puts(data) }