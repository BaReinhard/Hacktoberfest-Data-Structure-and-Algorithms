def selection_sort(array)
  i = 0

  loop do
    j = i
    min_index = i

    loop do
      if array[min_index] > array[j]
        min_index = j
      end
      j += 1
      break if j == array.size
    end

    array[i], array[min_index] = array[min_index], array[i]

    i += 1
    break if i == array.size
  end

  array
end

numbers = [4, 2, 8, 1, 30, 0, 10, 16]

puts "Unsorted: #{numbers}"

puts "Sorted: #{selection_sort(numbers)}"
