"""

    Most operations on a linked list have O(n) time, so linked lists are
    generally slower than arrays. However, they are also much more flexible
    -- rather than having to copy large chunks of memory around as with an
    array, many operations on a linked list just require you to change a
    few pointers.

    The reason for the O(n) time is that you can't simply write list[2] to
    access node 2 from the list. If you don't have a reference to that
    node already, you have to start at the head and work your way down to
    that node by following the next pointers (or start at the tail and
    work your way back using the previous pointers).

    But once you have a reference to a node, operations like insertion and
    deletion are really quick. It's just that finding the node is slow.

    This means that when you're dealing with a linked list, you should insert
    new items at the front whenever possible. That is an O(1) operation.

    Likewise for inserting at the back if you're keeping track of
    the tail pointer.
"""


class Node(object):
    def __init__(self, value):
        self._value = value
        self._next = None
        self._previous = None

    def __repr__(self):
        return self._value

    @property
    def value(self):
        return self._value

    @property
    def next(self):
        return self._next

    @property
    def previous(self):
        return self._previous

    @value.setter
    def value(self, new_value):
        self._value = new_value

    @next.setter
    def next(self, new_next):
        self._next = new_next

    @previous.setter
    def previous(self, new_pre):
        self._previous = new_pre


class LinkList(object):
    def __init__(self):
        self._head = None

    def __getitem__(self, index):
        node = self.find_node_at(index)
        return node.value

    def __repr__(self):
        s = '['
        node = self._head

        while node is not None:
            s += str(node.value)
            node = node.next
            if node is not None:
                s += ', '

        return s + ']'

    @property
    def is_empty(self):
        return self._head is None

    @property
    def first(self):
        return self._head

    @property
    def last(self):
        node = self._head
        if not node:
            return None

        while node.next is not None:
            node = node.next

        return node

    @property
    def count(self):
        node = self._head
        if node:
            _count = 1
            while node.next is not None:
                node = node.next
                _count += 1
            return _count
        else:
            return 0

    def append(self, element):
        new_node = Node(element)
        last = self.last
        if last:
            new_node.previous = last
            last.next = new_node
        else:
            self._head = new_node

    def insert(self, node, index):
        new_node = Node(node)
        if index == 0:
            new_node.next = self._head
            self._head.previous = new_node
            self._head = new_node

        else:
            pre = self.find_node_at(index - 1)
            next = pre.next

            new_node.previous = pre
            new_node.next = next
            pre.next = new_node
            next.previous = new_node

    def find_node_at(self, index):
        if index == 0:
            return self._head
        else:
            node = self._head.next
            for i in range(1, index):
                node = node.next
                if node is None:
                    break
            return node

    def remove_all(self):
        self._head = None

    def remove(self, node):
        pre = node.previous
        next = node.next

        if pre:
            pre.next = next
        else:
            self._head = next

        if next:
            next.previous = pre

        node.previous = None
        node.next = None

        return node.value

    def remove_at(self, index):
        node = self.find_node_at(index)
        try:
            return self.remove(node)
        except ValueError:
            raise

    def remove_last(self):
        try:
            return self.remove(self.last)
        except ValueError:
            raise


if __name__ == '__main__':
    list = LinkList()
    print(list.is_empty)  # True
    print(list.first)  # None

    list.append('Hello')
    print(list.is_empty)  # False
    print(list.first.value)  # Hello
    print(list.last.value)  # Hello
    print(list)

    list.append('World')
    print(list.first.value)  # Hello
    print(list.last.value)  # World
    print(list)

    print(list.first.previous)  # None
    print(list.first.next.value)  # World
    print(list.last.previous.value)  # Hello
    print(list.last.next)  # None

    print(list.find_node_at(0).value)  # Hello
    print(list.find_node_at(1).value)  # World

    print(list[0])  # Hellow
    print(list[1])  # World

    list.insert('Python', 1)
    print(list[0])  # Hello
    print(list[1])  # Python
    print(list[2])  # World
    print(list)

    print(list.remove(list.first))  # Hello
    print(list.count)  # 2
    print(list[0])  # Python
    print(list[1])  # World

    print(list.remove_last())  # World
    print(list.count)  # 1
    print(list[0])  # Python

    print(list.remove_at(0))  # Python
    print(list.count)  # 0

    print(list)
