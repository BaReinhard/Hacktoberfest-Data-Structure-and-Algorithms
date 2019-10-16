package bst_operations;

import java.util.ArrayList;

/**
 * Two nodes of a BST are swapped, correct the BST
 */
public class CorrectBST {
    public static void main(String[] args) {
        new CorrectBST().demo();
    }

    private void demo() {
        Node n = new Node(10);
        n.left = new Node(5);
        n.left.left = new Node(2);
        n.left.right = new Node(20);
        n.right = new Node(8);
        /*
         10
        /  \
       5    8
      / \
     2   20
*/
        ArrayList<Node> list = new ArrayList<Node>();
        display(n);
        balanceBST(n, list, Integer.MIN_VALUE, Integer.MAX_VALUE);
        System.out.println();
        list.get(0).data = list.get(0).data + list.get(1).data;
        list.get(1).data = list.get(0).data - list.get(1).data;
        list.get(0).data = list.get(0).data - list.get(1).data;
        System.out.println("After");
        display(n);
    }

    private void display(Node n) {
        if (n != null) {
            display(n.left);
            System.out.print(n.data + "\t");
            display(n.right);
        }
    }

    private void balanceBST(Node n, ArrayList<Node> list, int min, int max) {
        if (n == null) {
            return;
        }
        if (n.data > max || n.data < min) {
            list.add(n);
        }
        balanceBST(n.left, list, min, n.data);
        balanceBST(n.right, list, n.data, max);

    }
}
