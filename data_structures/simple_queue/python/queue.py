class Queue:
    def __init__(self):
        self.data = []

    def enqueue(self, item):
        self.data.insert(0, item)

    def dequeue(self):
        return self.data.pop()

    def peek(self):
        return self.data[-1]
