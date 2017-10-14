def linear_search(target, array)
  index = 0

  while index < array.length do
    if array[index] == target
      return "It is at index #{index}"
    end
    index += 1
  end
  return "We don't have that one."
end

puts "Type an integer."
integer = gets.chomp.to_i
puts linear_search(integer, [2,3,5,8,25,4,6,6357,49,323,1113,15,436,67])
