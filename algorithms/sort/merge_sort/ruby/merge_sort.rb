def sort(numbers)
  return numbers if numbers.size <= 1

  arr_len = numbers.size
  half_size = (arr_len / 2).round

  left_array  = numbers.take(half_size)
  right_array = numbers.drop(half_size)

  sorted_left = sort(left_array)
  sorted_right = sort(right_array)

  merge(sorted_left, sorted_right)
end

def merge(left, right)
  return left if right.empty?
  return right if left.empty?

  smallest_number = if left.first <= right.first
    left.shift
  else
    right.shift
  end
  recursive = merge(left, right)
  [smallest_number].concat(recursive)
end

arr = [1,8,4,5,7,3,9,2,6]
sort(arr)
# => [1, 2, 3, 4, 5, 6, 7, 8, 9]
