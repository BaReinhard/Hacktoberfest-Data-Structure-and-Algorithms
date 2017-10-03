def quicksort(array)
  return array if array.length <= 1

  pivot_index = (array.length / 2).to_i
  pivot_value = array[pivot_index]
  array.delete_at(pivot_index)

  lesser = Array.new
  greater = Array.new

  array.each do |x|
    if x <= pivot_value
      lesser << x
    else
      greater << x
    end
  end

  quicksort(lesser) + [pivot_value] + quicksort(greater)
end

arr = [1,8,4,5,7,3,9,2,6]
quicksort(arr)
# => [1, 2, 3, 4, 5, 6, 7, 8, 9]
