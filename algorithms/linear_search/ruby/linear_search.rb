def linearSearch (data, target) 
  result = nil
  for i in 0..data.size-1
    if (data[i] == target)
      return "Found element #{target} in position #{i}"
    end
  end
end

puts linearSearch([1,2,3,4], 3)

