# Trees:
#   http://en.wikipedia.org/wiki/Tree_(data_structure)
#   http://en.wikipedia.org/wiki/Tree_traversal
#   http://en.wikipedia.org/wiki/Binary_tree

class BinaryTree(object):
    """Binary tree."""
    def __init__(self, name='', left=None, right=None):
        self.name = name
        self.left = left
        self.right = right
    def __str__(self):
        return str(self.name)

def walk_btree_df_preorder(node, visit):
    """Depth-first pre-order."""
    if node is None:
        return
    visit(node)
    walk_btree_df_preorder(node.left, visit)
    walk_btree_df_preorder(node.right, visit)

def walk_btree_df_inorder(node, visit):
    """Depth-first in-order."""
    if node is None:
        return
    walk_btree_df_inorder(node.left, visit)
    visit(node)
    walk_btree_df_inorder(node.right, visit)

def walk_btree_df_postorder(node, visit):
    """Depth-first post-order."""
    if node is None:
        return
    walk_btree_df_postorder(node.left, visit)
    walk_btree_df_postorder(node.right, visit)
    visit(node)

def walk_btree_df_preorder_iter(node, visit):
    parent = []
    while parent or node:
        if node:
            visit(node)
            if node.right:
                parent.append(node.right)
            node = node.left
        else:
            node = parent.pop()

def walk_btree_df_inorder_iter(node, visit):
    parent = []
    while parent or node:
        if node:
            parent.append(node)
            node = node.left
        else:
            node = parent.pop()
            visit(node)
            node = node.right

def walk_btree_df_postorder_iter(node, visit):
    parent = []
    last_visited = None
    while parent or node:
        if node:
            parent.append(node)
            node = node.left
        else:
            peeknode = parent[-1]
            if peeknode.right and last_visited != peeknode.right:
                node = peeknode.right
            else:
                visit(peeknode)
                last_visited = parent.pop()

def walk_btree_bf_iter(node, visit):
    to_visit = [node]
    while to_visit:
        new_to_visit = []
        for node in to_visit:
            if node:
                visit(node)
                new_to_visit.append(node.left)
                new_to_visit.append(node.right)
        to_visit = new_to_visit

def walk_btree_df_preorder_gen(node):
    parent = []
    while parent or node:
        if node:
            yield node
            if node.right:
                parent.append(node.right)
            node = node.left
        else:
            node = parent.pop()

def walk_btree_df_inorder_gen(node):
    parent = []
    while parent or node:
        if node:
            parent.append(node)
            node = node.left
        else:
            node = parent.pop()
            yield node
            node = node.right

def walk_btree_df_postorder_gen(node):
    parent = []
    last_visited = None
    while parent or node:
        if node:
            parent.append(node)
            node = node.left
        else:
            peeknode = parent[-1]
            if peeknode.right and last_visited != peeknode.right:
                node = peeknode.right
            else:
                yield peeknode
                last_visited = parent.pop()

def walk_btree_bf_gen(node):
    to_visit = [node]
    while to_visit:
        new_to_visit = []
        for node in to_visit:
            if node:
                yield node
                new_to_visit.append(node.left)
                new_to_visit.append(node.right)
        to_visit = new_to_visit


class Tree(object):
    """Generic tree."""
    def __init__(self, name='', children=None):
        self.name = name
        if children is None:
            children = []
        self.children = children
    def __str__(self):
        return str(self.name)

def walk_tree_df_preorder(node, visit):
    """Depth-first pre-order."""
    visit(node)
    for child in node.children:
        walk_tree_df_preorder(child, visit)

def walk_tree_df_postorder(node, visit):
    """Depth-first post-order."""
    for child in node.children:
        walk_tree_df_preorder(child, visit)
    visit(node)

def walk_tree_bf(node, visit):
    """Breadth-first (level order)."""
    to_visit = [node]
    while to_visit:
        new_to_visit = []
        for node in to_visit:
            visit(node)
            new_to_visit.extend(node.children)
        to_visit = new_to_visit

def walk_tree_bf_gen(node):
    """Breadth-first (generator)."""
    to_visit = [node]
    while to_visit:
        new_to_visit = []
        for node in to_visit:
            yield node
            new_to_visit.extend(node.children)
        to_visit = new_to_visit


if __name__ == '__main__':
    T = Tree
    BT = BinaryTree
    def visit(n):
        print n
    #    *
    #   / \
    #  1   +
    #     / \
    #    2   -
    #       / \
    #      3   4
    bt = BT('*', BT(1), BT('+', BT(2), BT('-', BT(3), BT(4))))
    print '->Binary Tree, Depth-First, Pre-Order'
    walk_btree_df_preorder(bt, visit)
    print '->Binary Tree, Depth-First, In-Order'
    walk_btree_df_inorder(bt, visit)
    print '->Binary Tree, Depth-First, Post-Order'
    walk_btree_df_postorder(bt, visit)

    print '->Binary Tree, Depth-First, Pre-Order (iteractive)'
    walk_btree_df_preorder_iter(bt, visit)
    print '->Binary Tree, Depth-First, In-Order (iteractive)'
    walk_btree_df_inorder_iter(bt, visit)
    print '->Binary Tree, Depth-First, Post-Order (iteractive)'
    walk_btree_df_postorder_iter(bt, visit)

    print '->Binary Tree, Depth-First, Pre-Order (generator)'
    for n in walk_btree_df_preorder_gen(bt):
        print n
    print '->Binary Tree, Depth-First, In-Order (generator)'
    for n in walk_btree_df_inorder_gen(bt):
        print n
    print '->Binary Tree, Depth-First, Post-Order (generator)'
    for n in walk_btree_df_postorder_gen(bt):
        print n
    print '->Binary Tree, Breadth-First (generator)'
    for n in walk_btree_bf_gen(bt):
        print n

    #           if
    #         /  | \
    #       /    |   \
    #     cond  true false
    #      |     |     |
    #    equal  print end
    #     /\     |
    #    x  y   OK
    t = T('if', [T('cond', [T('equal', [T('x'), T('y')])]),
                 T('true', [T('print', [T('OK')])]),
                 T('false', [T('end')])])
    print '=>Tree, Depth-Frist, Pre-Order'
    walk_tree_df_preorder(t, visit)
    print '=>Tree, Depth-Frist, Post-Order'
    walk_tree_df_postorder(t, visit)
    print '=>Tree, Breadth-Frist'
    walk_tree_bf(t, visit)
    print '=>Tree, Breadth-Frist (generator)'
    for n in walk_tree_bf_gen(t):
        print n