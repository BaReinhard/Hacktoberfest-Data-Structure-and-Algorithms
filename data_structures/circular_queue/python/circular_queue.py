class CircularQueue:

    def __init__(self):
        self.queue = list()
        self.head = 0
        self.tail = 0
        self.maxSize = 8

    def enqueue(self, element):
        if self.size() == self.maxSize-1:
            return ("Queue is full.")
        self.queue.append(element)
        self.tail = (self.tail + 1) % self.maxSize
        return True

    def dequeue(self):
        if self.size()==0:
            return ("Empty queue. Cannot dequeue.") 
        element = self.queue[self.head]
        self.head = (self.head + 1) % self.maxSize
        return element

    def size(self):
        if self.tail>=self.head:
            return (self.tail-self.head)
        return (self.maxSize - (self.head-self.tail))