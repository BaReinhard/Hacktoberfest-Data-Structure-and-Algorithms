def binary_search(array, searched, beginning = 0, ending = array.length - 1)
    middle = ((beginning + ending) / 2)

    return "I don't have that one." if beginning > ending

    if array[middle] == searched
        middle
    elsif array[middle] < searched
        binary_search(array, searched, middle + 1, ending)
    else
        binary_search(array, searched, beginning, middle - 1)
    end
end

binary_search([:A, :B, :C, :D, :E, :F, :G, :H], :N) # => "I don't have that one."
binary_search([1, 2, 3, 45, 194, 23500, 27394, 99999], 45) # => 3
binary_search([:A, :B, :C, :D, :E, :F, :G, :H], :B) # => 1
binary_search([:A, :B, :C, :D, :E, :F, :G, :H], :G) # => 6
binary_search([23, 34, 7543, 87654], 7) # => "I don't have that one."
