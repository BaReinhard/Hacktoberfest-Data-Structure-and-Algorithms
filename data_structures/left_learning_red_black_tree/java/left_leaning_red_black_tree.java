// Simplest Java Implementation of Left leaning Red Black Trees.
public class left_leaning_red_black_tree<Key extends Comparable<Key>, Value> {
	private static final boolean RED = true;
	private static final boolean BLACK = false;
	private Node root;

	private class Node {
		private Key key;
		private Value val;
		private Node left, right;
		private boolean color;
		Node(Key key, Value val) {
		    this.key = key;
		    this.val = val;
		    this.color = RED;
		}
	}

	public Value search(Key key) {
		Node x = root;
		while (x != null) {
			int cmp = key.compareTo(x.key);
			if (cmp == 0) return x.val;
			else if (cmp < 0) x = x.left;
			else if (cmp > 0) x = x.right;
		}
		return null;
	}

	public void insert(Key key, Value value) {
	    root = insert(root, key, value);
	    root.color = BLACK;
	}

	private Node insert(Node h, Key key, Value value) {
		if (h == null) return new Node(key, value);
		if (isRed(h.left) && isRed(h.right)) colorFlip(h);
		int cmp = key.compareTo(h.key);
		if (cmp == 0) h.val = value;
		else if (cmp < 0) h.left = insert(h.left, key, value);
		else h.right = insert(h.right, key, value);
		if (isRed(h.right) && !isRed(h.left)) h = rotateLeft(h);
		if (isRed(h.left) && isRed(h.left.left)) h = rotateRight(h);
		return h;
	}

	private boolean isRed(Node h) {
		if(h == null) return false;
        return h.color;
	}

	void colorFlip(Node h) {
		h.color = !h.color;
		h.left.color = !h.left.color;
		h.right.color = !h.right.color;
	}

	private Node rotateLeft(Node h) {
		Node x = h.right;
		h.right = x.left;
		x.left = h;
		x.color = h.color;
		h.color = RED;
		return x;
	}

	private Node rotateRight(Node h) {
		Node x = h.left;
		h.left= x.right;
		x.right= h;
		x.color = h.color;
		h.color = RED;
		return x;
	}

    public void preorder() {
        preorder(root);
    }

    private void preorder(Node root) {
        if(root == null) return;
        System.out.println(root.key);
        preorder(root.left);
        preorder(root.right);
    }

    public void inorder() {
        inorder(root);
    }

    private void inorder(Node root) {
        if(root == null) return;
        inorder(root.left);
        System.out.println(root.key);
        inorder(root.right);
    }

    public void postorder() {
        postorder(root);
    }

    private void postorder(Node root) {
        if(root == null) return;
        postorder(root.left);
        postorder(root.right);
        System.out.println(root.key);
    }

	public static void main(String[] args) {
		left_leaning_red_black_tree <Integer, Integer> l1 = new left_leaning_red_black_tree<>();
		l1.insert(1, 10);
		l1.insert(2, 20);
		l1.insert(4, 30);
		l1.insert(6, 75);
		l1.insert(12, 89);
		l1.insert(19, 134);
		l1.insert(38, 12);
        l1.preorder();
	}
}
