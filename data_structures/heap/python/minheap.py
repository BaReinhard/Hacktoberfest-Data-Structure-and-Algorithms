import heapq

class Heap(object): 
    def __init__(self):
        self._heap = []

    def push(self, priority, item):
        assert priority >= 0
        heapq.heappush(self._heap, (priority, item))

    def pop(self):
        item = heapq.heappop(self._heap)[1] 
        return item

    def __len__(self):
        return len(self._heap)

    def __iter__(self):
        return self

    def next(self):
        try:
            return self.pop()
        except IndexError:
            raise StopIteration