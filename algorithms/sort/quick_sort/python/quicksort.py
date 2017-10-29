def partition(li, start, end):
    pivot = li[start]
    left = start + 1
    right = end
    done = False

    while not done:
        while left <= right and li[left] <= pivot:
            left += 1
        while right >= left and li[right] >= pivot:
            right -= 1
        if right < left:
            done = True
        else:
            li[left], li[right] = li[right], li[left]
    li[start], li[right] = li[right], li[start]
    return right


def quicksort(li, start=0, end=None):
    if not end:
        end = len(li) - 1
    if start < end:
        pivot = partition(li, start, end)
        # Recursively perform same operation on first and last halves of list
        quicksort(li, start, pivot - 1)
        quicksort(li, pivot + 1, end)
    return li
