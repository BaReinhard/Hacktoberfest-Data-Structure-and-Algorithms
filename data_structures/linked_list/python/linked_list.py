class Node:
    def __init__(self, data=None, next_node=None):
        self.data = data
        self.next = next_node
        self.prev = None

    def __repr__(self):
        return self.data or ''


class LinkedList:
    '''
    Implementation of Linked list data structure
    '''

    def __init__(self, data_iterable):
        self.head = None
        for data in data_iterable:
            self.add(data)

    def add(self, data):
        node = Node(data)
        node.next = self.head
        self.head = node
        if node.next:
            node.next.prev = node

    def search(self, data):
        node = self.head
        while node:
            if node.data == data:
                return node
            node = node.next
        return None

    def remove(self, node):
        if node is self.head:
            self.head = node.next
        else:
            node.prev.next = node.next
        if node.next:
            node.next.prev = node.prev
    
    def __repr__(self):
        node = self.head
        data = []
        while node:
            data.append(node.data)
            node = node.next
        return ' '.join(data)


if __name__ == '__main__':
    l = LinkedList(['d', 'c', 'b'])
    assert str(l) == 'b c d'
    l.add('a')
    assert str(l) == 'a b c d'
    l.remove(l.search('a'))
    l.remove(l.search('c'))
    assert str(l) == 'b d'

