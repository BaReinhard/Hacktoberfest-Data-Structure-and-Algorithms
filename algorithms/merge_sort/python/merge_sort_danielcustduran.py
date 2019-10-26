 
def merge_sort(array):
    if len(array) >= 2:
        middle = len(array) // 2
        right_array = merge_sort(array[middle:])
        left_array = merge_sort(array[:middle])
        return merge(left_array, right_array)
    else:
        return array


def merge(left_array, right_array):
    sorted_list = []
    while left_array and right_array:
        if left_array[0] < right_array[0]:
            sorted_list.append(left_array.pop(0))
        else:
            sorted_list.append(right_array.pop(0))
    while right_array:
        sorted_list.append(right_array.pop())
    while left_array:
        sorted_list.append(left_array.pop())
    return sorted_list


print(f" Array original {[43, 3, 27, 1]}")
print(f"{merge_sort([43, 3, 27, 1])}")