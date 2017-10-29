def insertion_sort(numbers)
  for i in 1...numbers.length
    key = numbers[i]
    j = i - 1
    while j >= 0 and numbers[j] > key
      numbers[j+1] = numbers[j]
      j = j - 1
    end
    numbers[j+1] = key
  end
  numbers
end

unsorted = [5, 2, 6, 7, 20, 9, 1, 3]

puts "Unsorted " + unsorted.inspect

sorted = insertion_sort(unsorted)
puts "Sorted " + sorted.inspect
