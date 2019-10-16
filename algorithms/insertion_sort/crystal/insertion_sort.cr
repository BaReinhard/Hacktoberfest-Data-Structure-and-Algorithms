def insertion_sort(array)
  x = 1
  loop do
    i = x

    while i > 0 && array[i-1] > array[i]
      array[i], array[i - 1] = array[i - 1], array[i]
      i -= 1
    end

    x += 1
    break if x == array.size
  end

  array
end

numbers = [4, 2, 8, 1, 30, 0, 10, 16]

puts "Unsorted: #{numbers}"

puts "Sorted: #{insertion_sort(numbers)}"
