package bst_operations;

public class CheckBST {
    public static void main(String[] args) {
        new CheckBST().demo();
    }

    private void demo() {
        Node n = new Node(4);
        // left
        n.left = new Node(2);
        n.left.left = new Node(1);
        n.left.right = new Node(3);

        //right
        n.right = new Node(5);
        System.out.println(isBST(n, Integer.MIN_VALUE, Integer.MAX_VALUE));
    }

    private boolean isBST(Node n, int min, int max) {
        if (n == null) {
            return true;
        }
        if (n.data < min || n.data > max) {
            return false;
        }
        if(n.data == max || n.data == min) {
            System.out.println("duplication of data");
            return false;
        }
        return isBST(n.left, min, n.data) && isBST(n.right, n.data, max);
    }
}

