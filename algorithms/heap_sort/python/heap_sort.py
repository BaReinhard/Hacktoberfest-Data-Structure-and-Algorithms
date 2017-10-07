from heapq import heappush, heappop

def heap_sort(heap_iterable):
    '''
    Heap sort implementation
    '''
    heap = []
    for val in heap_iterable:
        heappush(heap, val)
    return [heappop(heap) for _ in range(len(heap))]

# Test
if __name__ == '__main__':
    test_cases = (
        [1, 3, 5, 7, 9, 2, 4, 6, 8, 0],
        [3, 15, 68, 34, 39, 85, 85, 71, 47, 84], 
        [3, 10, 68, 34, 15, 85, 85, 71, 47, 84, 39], 
        [2, 10, 3, 34, 15, 68, 85, 71, 47, 84, 39, 85],
        [1, 10, 2, 34, 15, 3, 85, 71, 47, 84, 39, 85, 68],
        range(50)
    )
    for iterable in test_cases:
        assert heap_sort(iterable) == sorted(iterable)
