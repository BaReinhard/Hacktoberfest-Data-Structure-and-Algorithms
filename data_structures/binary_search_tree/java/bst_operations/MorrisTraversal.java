package bst_operations;


/**
 * Created by kalsi on 30/08/17.
 * Inorder traversal without recursion or stacks
 */
public class MorrisTraversal {
    public static void main(String[] args) {
        new MorrisTraversal().demo();
    }

    private void demo() {
        Node n = new Node(8);
        // left
        n.left = new Node(3);
        n.left.left = new Node(1);
        n.left.right = new Node(6);
        n.left.right.left = new Node(4);
        n.left.right.right = new Node(7);

        //right
        n.right = new Node(10);
        n.right.right = new Node(14);
        n.right.right.left = new Node(13);

        /*
                            8
                        3      10
                     1    6        14
                        4   7   13
        *
        * */
        inorderIterative(n);
    }


    private void inorderIterative(Node n) {
        while (n != null) {
            if (n.left == null) {
                System.out.print(n.data + "\t");
                n = n.right;
            }
            Node predecessor = getPredecessor(n);
            if (predecessor.right == null) {
                predecessor.right = n;
                n = n.left;
            } else {
                predecessor.right = null;
                System.out.print(n.data + "\t");
                n = n.right;
            }

        }
    }

    private Node getPredecessor(Node n) {
        Node temp = n.left;
        while( temp.right != null && temp.right != n) {
            temp = temp.right;
        }
        return temp;
    }
}
