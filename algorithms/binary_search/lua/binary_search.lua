function BinarySearch ( arr, value )
    l = 1
    r = #arr

    while l <= r do
        mid = math.floor( (l + r)/2 )
        if value > arr[mid] then
            l = mid + 1
        elseif value < arr[mid] then
            r = mid - 1
        else
            return arr[mid]
        end
    end
end