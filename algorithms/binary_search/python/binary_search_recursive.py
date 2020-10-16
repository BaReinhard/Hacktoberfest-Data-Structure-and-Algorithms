# Recursive Binary Search Algorithm
def binary_search_recursive(arr, target, low, high):
    if low > high:
        return -1
    if low == high:
        if arr[low] == target:
            return low
    else:
        mid = (low + high) // 2
        if target > arr[mid]:
            return binary_search_recursive(arr, target, mid + 1, high)
        elif target < arr[mid]:
            return binary_search_recursive(arr, target, low, mid - 1)
        elif target == arr[mid]:
            return mid