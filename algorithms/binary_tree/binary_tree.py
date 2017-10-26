
"""
Binary Tree and basic properties
1. In-Order Traversal
2. Pre-Order Traversal
3. Post-Order Traversal
4. Level-Order Traversal
"""
from collections import deque


class BinaryTree(object):
    """
    Representation of a general binary tree
    data: value of element
    left: Left subtree
    right: Right subtree
    """

    def __init__(self, data, left=None, right=None):
        if data is None:
            raise ValueError('data cannot be null')
        self.data = data
        self.left = left
        self.right = right

    def insert(self, data):
        raise NotImplementedError('Method insert is not Implemented')

    def delete(self, data):
        raise NotImplementedError('Method delete is not implemented')

    def inorder_traversal(self, write=True):
        """
        Return list of node data as inorder traversal. If write is True then print as well.
        This is a iterative tree inorder traversal.
        Algorithm:
        1. Create a stack of nodes node_stack
        2. Mark root as current
        3. While current is not none or node_stack is not empty
            a. While current is not empty push current to nde_stack and reassign current to current->left
            b. If current is empty and node_stack is not empty then pop the top of stack and print that node
            c. mark current as poped_node->right
        """
        traversal_lis = []
        node_stack = []
        current = self
        while current or node_stack:
            while current:
                node_stack.append(current)
                current = current.left
            if node_stack:
                node = node_stack.pop()
                traversal_lis.append(node.data)
                current = node.right
        if write:
            for item in traversal_lis:
                print(item, end=' ')
        return traversal_lis

    def preorder_traversal(self, write=True):
        """
        Return list of node data as preorder traversal. If write is true then print as well.
        Algorithm:
        1. Create stack of nodes as node_stack
        2. Mark root as current
        3. While current is not none or node_stack is not empty
            a. While current is not empty
                i. Push current to node_stack
                ii. Add current->data to traversal_list
                iii. Reassign current to current->left
            b. If node_stack is not empty then pop the topmost node from node_stack and assign current to
                poped_node->right
        """
        traversal_lis = []
        node_stack = []
        current = self
        while current or node_stack:
            while current:
                node_stack.append(current)
                traversal_lis.append(current.data)
                current = current.left
            if node_stack:
                node = node_stack.pop()
                current = node.right
        if write:
            for item in traversal_lis:
                print(item, end=' ')
        return traversal_lis

    def postorder_traversal(self, write=True):
        """
        Return list of node data as postorder traversal. If write is true then print as well.
        Algorithm:
        1. Create stack of nodes as node_stack
        2. Mark root as current
        3. While current is not None or node_stack is not empty
            a. While current is not None
                i. Push current to node_stack
                ii. Append current->data to traversal_list
                iii. Reassign current as current->right !IMPORTANT: Here we're iterating on current-right as we're doing
                    postorder traversal
            b. If node_stack is not empty then pop top node and assign poped_node->left to current
        """
        traversal_lis = []
        node_stack = []
        current = self
        while current or node_stack:
            while current:
                node_stack.append(current)
                traversal_lis.append(current.data)
                current = current.right
            if node_stack:
                node = node_stack.pop()
                current = node.left
        if write:
            for item in traversal_lis:
                print(item, end=' ')
        return traversal_lis

    def levelorder_traversal(self, write=True):
        """
        Return list of node data as level order traversal. If write is true then print as well.
        Algorithm:
        1. Maintain a queue of nodes to process as node_queue
        2. Push root to node_queue
        3. While node_queue is not empty
            a. Get top node of node_queue as top
            b. Push top->data to traversal_list
            c. Append top->left and top->right into node_queue if they are not null
        """
        traversal_list = []
        node_queue = deque()
        node_queue.append(self)
        while node_queue:
            top = node_queue.popleft()
            traversal_list.append(top.data)
            if top.left:
                node_queue.append(top.left)
            if top.right:
                node_queue.append(top.right)
        if write:
            for item in traversal_list:
                print(item, end=' ')
        return traversal_list


def main():
    """
    Tree Structure:
            1
          /   \
         2     3
        / \
       4   5
    """
    tree = BinaryTree(1)
    tree.left = BinaryTree(2)
    tree.right = BinaryTree(3)
    tree.left.left = BinaryTree(4)
    tree.left.right = BinaryTree(5)

    assert tree.inorder_traversal(write=False) == [4, 2, 5, 1, 3]
    assert tree.preorder_traversal(write=False) == [1, 2, 4, 5, 3]
    assert tree.postorder_traversal(write=False) == [1, 3, 2, 5, 4]
    assert tree.levelorder_traversal(write=False) == [1, 2, 3, 4, 5]


if __name__ == '__main__':
    main()