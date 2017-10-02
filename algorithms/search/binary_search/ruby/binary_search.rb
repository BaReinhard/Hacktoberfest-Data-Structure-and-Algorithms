def binary_search(an_array, item)
  first = 0
  last = an_array.length - 1

  while first <= last
    i = (first + last) / 2

    if an_array[i] == item
      return i
    elsif an_array[i] > item
      last = i - 1
    elsif an_array[i] < item
      first = i + 1
    else
      return -1
    end
  end
end

arr = [0,1,2,3,4,27,5,6,7,8,9]

binary_search(arr, 27)
# => 5
