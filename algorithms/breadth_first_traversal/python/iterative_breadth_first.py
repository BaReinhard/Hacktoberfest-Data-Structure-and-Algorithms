class Node:
    def __init__(self, data):
        self.value = data
	self.left = None
        self.right = None

def breadth_first_traversal(A):
    """
    :param: Root Node of type Node
    :return: list of values as obtained from
    breadth first traversal.
    """
    queue = []
    nodes = []
    if A:
        queue.append(A)
        while len(queue)>0:
            node = queue.pop(0)
            nodes.append(node.value)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
    return nodes


if __name__ == '__main__':
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    print(breadth_first_traversal(root))
