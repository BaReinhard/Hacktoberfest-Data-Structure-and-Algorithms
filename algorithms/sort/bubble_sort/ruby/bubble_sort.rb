def bubble_sort(array)
  n = array.length
  loop do
    swapped = false

    (n-1).times do |i|
      next unless array[i] > array[i+1]
      array[i], array[i+1] = array[i+1], array[i]
      swapped = true
    end

    break if not swapped
  end

  array
end

arr = [1,4,5,2,6,7,8,3]
bubble_sort(arr)
# => [1, 2, 3, 4, 5, 6, 7, 8]
