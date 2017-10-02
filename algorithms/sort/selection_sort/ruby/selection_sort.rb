def selection_sort(input_arr)
  arr = input_arr.dup
  n = arr.size - 1

  n.times do |i|
    index_min = i
    (i + 1).upto(n) do |j|
      index_min = j if arr[j] < arr[index_min]
    end
    arr[i], arr[index_min] = arr[index_min], arr[i] if index_min != i
  end
  arr
end

arr = [1,8,4,5,7,3,9,2,6]
selection_sort(arr)
# => [1, 2, 3, 4, 5, 6, 7, 8, 9]
