def bogosort(arr)
  arr.shuffle! while !arr.each_cons(2).all? do |x, y|
    x <= y
  end
end
array = [ 0, 5, 4, 3, 2, 8, 7, 1, 9, 6]
bogosort(array)
puts array # => 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
