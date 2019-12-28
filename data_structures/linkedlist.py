class Node:
    def __init__(self, data=None):
        self.data=data
        self.next=None #Node's will hold data & pointer to next node

class LinkedList:
    def __init__(self):
        self.head=Node() 
    def append(self, data):
        node = Node(data)
        cur = self.head
        while cur.next != None:
            cur = cur.next
        cur.next=node
    def traverse(self):
        cur = self.head
        while cur.next != None:
            cur = cur.next
            print(cur.data, "->")
    def remove(self, data):
        cur = self.head
        while cur.next != None:
            if cur.data == data:
                cur.next = None

LL = LinkedList()
LL.append(5)
LL.append(6)
LL.append(7)
LL.append(8)
LL.traverse()
