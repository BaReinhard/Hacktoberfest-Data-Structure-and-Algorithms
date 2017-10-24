class Node():
    def __init__(self, next_node=None, previous_node=None, data=None):
        self.next_node = next_node
        self.previous_node = previous_node
        self.data = data



class LinkedList():
    def __init__(self, node):
        assert isinstance(node, Node)
        self.first_node = node
        self.last_node = node

    def push(self, node):
        '''Pushes the node <node> at the "front" of the ll
        '''
        node.next_node = self.first_node
        node.previous_node = None
        self.first_node.previous_node = node
        self.first_node = node

    def pop(self):
        '''Pops the last node out of the list'''
        old_last_node = self.last_node
        to_be_last = self.last_node.previous_node
        to_be_last.next_node = None
        old_last_node.previous_node = None

        # Set the last node to the "to_be_last"
        self.previous_node = to_be_last

        return old_last_node

    def remove(self, node):
        '''Removes and returns node, and connects the previous and next
        nicely
        '''
        next_node = node.next_node
        previous_node = node.previous_node

        previous_node.next_node = next_node
        next_node.previous_node = previous_node

        # Make it "free"
        node.next_node = node.previous_node = None

        return node

    def __str__(self):
        next_node = self.first_node
        s = ""
        while next_node:
            s += "--({:0>2d})--\n".format(next_node.data)
            next_node = next_node.next_node

        return s

        return 


node1 = Node(data=1)

linked_list = LinkedList(node1)


for i in xrange(10):
    if i == 5:
        node5 = Node(data=5)
        linked_list.push(node5)
    else:
        linked_list.push(Node(data=i))

print linked_list

print "popping"
print linked_list.pop().data

print "\n\n"
print linked_list


print "\n\n"
linked_list.push(Node(data=10))

print "\n\n"
print linked_list


linked_list.remove(node5)

print "\n\n"
print linked_list

