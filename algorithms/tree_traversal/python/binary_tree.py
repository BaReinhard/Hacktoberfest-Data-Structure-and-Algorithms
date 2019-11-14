class Tree(object):

    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def inorder(root):
    if root is None:
        return

    inorder(root.left)
    print(root.data)
    inorder(root.right)


def post_order(root):
    if root is None:
        return

    post_order(root.left)
    post_order(root.right)
    print(root.data)


def pre_order(root):
    if root is None:
        return

    print(root.data)
    pre_order(root.left)
    pre_order(root.right)