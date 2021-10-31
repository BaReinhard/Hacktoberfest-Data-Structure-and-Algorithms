public class AVL {
    class Node {
        private int data, height;
        private Node left, right;
        public Node(int data, int height) {
            this.data = data;
            this.height = height;
        }
    }

    Node root = null;

    private int getHeight(Node root) {
        if(root == null) return 0;
        return root.height;
    }

    private int getBalance(Node root) {
        if(root == null) return 0;
        return (getHeight(root.left) - getHeight(root.right));
    }

    private Node rightRotate(Node root) {
        Node temp1 = root.left;
        Node temp2 = temp1.right;
        temp1.right = root;
        root.left = temp2;
        
        root.height = Math.max(getHeight(root.left), getHeight(root.right)) + 1;
        temp1.height = Math.max(getHeight(temp1.left), getHeight(temp1.right)) + 1;
        
        return temp1;
    }

    private Node leftRotate(Node root) {
        Node temp1 = root.right;
        Node temp2 = temp1.left;
        temp1.left = root;
        root.right = temp2;
 
        root.height = Math.max(getHeight(root.left), getHeight(root.right)) + 1;
        temp1.height = Math.max(getHeight(temp1.left), getHeight(temp1.right)) + 1;
        
        return temp1;
    }

    public void insert(int data) {
        root = insert(root, data, 0);
    }

    private Node insert(Node root, int data, int height) {
        if(root == null) return new Node(data, height);
        else if(root.data > data) root.left = insert(root.left, data, height+1);
        else if(root.data < data) root.right = insert(root.right, data, height+1);
        else return root;

        int balance = getBalance(root);

        if(balance > 1 && data < root.left.data) {
            return rightRotate(root);
        }
        else if(balance > 1 && data > root.left.data) {
            root.left = leftRotate(root.left);
            return rightRotate(root);
        }
        else if(balance < -1 && data > root.right.data) {
            return leftRotate(root);
        }
        else if(balance < -1 && data < root.right.data) {
            root.right = rightRotate(root.right);
            return leftRotate(root);
        }

        return root;
    }

    public void preorder() {
        preorder(root);
    }

    private void preorder(Node root) {
        if(root == null) return;
        System.out.println(root.data);
        preorder(root.left);
        preorder(root.right);
    }

    public static void main(String[] args) {
        AVL a1 = new AVL();
        a1.insert(10);
        a1.insert(20);
        a1.insert(30);
        a1.insert(40);
        a1.insert(50);
        a1.insert(25);
        a1.preorder();
    }
}
