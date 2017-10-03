def bubbleSort(array)
  count = 0
  while true
    swapped = false
    i = 0

    while true
      if array[i] > array[i + 1]
        array[i], array[i + 1] = array[i + 1], array[i]
        swapped = true
      end

      i += 1
      break if i == array.size - 1
    end

    break if !swapped

    count += 1
    break if count == array.size - 1
  end

  array
end

numbers = [4, 2, 8, 1, 0, 10]

puts "Unsorted: #{numbers}"

puts "Sorted: #{bubbleSort(numbers)}"
