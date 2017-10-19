class Heap
  def initialize
      @store = Array.new
  end

  def push(data)
    @store.push(data)
    tear_up(size - 1)
  end

  def top
    @store.first
  end

  def pop
    data = top
    if size > 1
      @store[0] = @store.pop
      tear_down(0)
    else
      @store.pop
    end
    return data
  end

  def size
    @store.size
  end

  private

  def tear_up(pos)
    return if pos == 0
    parent = (pos - 1) / 2

    if @store[parent] < @store[pos]
      @store[parent], @store[pos] = @store[pos], @store[parent]
      tear_up(parent)
    end
  end

  def tear_down(pos)
    return if pos >= size
    left = pos * 2 + 1
    right = pos * 2 + 2

    max_leaf = -1

    if left >= size
      max_leaf = -1
    elsif right >= size
      max_leaf = left
    else
      if @store[right] > @store[left]
        max_leaf = right
      else
        max_leaf = left
      end
    end

    if max_leaf != -1
      @store[max_leaf], @store[pos] = @store[pos], @store[max_leaf]
      tear_down(max_leaf)
    end
  end
end

# Usage
H = Heap.new
H.push(5)
H.push(3)
H.push(9)
H.push(10)
H.push(1)
H.push(4)

# 10
puts H.top()

# 10 9 5 4 3 1
while H.size() > 0 do
  puts H.pop()
end