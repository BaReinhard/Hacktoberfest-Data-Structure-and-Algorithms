class LinkedStack(object):
    class __Node(object):
        def __init__(self, val, next=None):
            self.val = val
            self.next = next
    
    def __init__(self):
        self.head = None
    
    def push(self, item):
        self.head = LinkedStack.__Node(item, self.head)
    
    def pop(self):
        if not self.isEmpty():
            rv = self.head.val
            self.head = self.head.next
            return rv
        raise Exception("LinkedStack is empty!")
    
    def isEmpty(self):
        return self.head is None


def main():
    s = LinkedStack()
    for i in range(1,11):
        s.push(i)
    
    for i in range(1,11):
        print(s.pop())
    
    print(s.pop())

if __name__ == '__main__':
    main()
