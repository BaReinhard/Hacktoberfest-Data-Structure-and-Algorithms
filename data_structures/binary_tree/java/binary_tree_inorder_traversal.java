import java.util.*;

class Node {
    int data;
    Node left, right;
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
public class binary_tree_inorder_traversal {
    static ArrayList < Integer > inOrderTrav(Node curr) {
        ArrayList < Integer > inOrder = new ArrayList < > ();
        Stack < Node > s = new Stack < > ();
        while (true) {
            if (curr != null) {
                s.push(curr);
                curr = curr.left;
            } else {
                if (s.isEmpty()) break;
                curr = s.peek();
                inOrder.add(curr.data);
                s.pop();
                curr = curr.right;
            }
        }
        return inOrder;
    }

    public static void main(String args[]) {

        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.left.right.left = new Node(8);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        root.right.right.left = new Node(9);
        root.right.right.right = new Node(10);

        ArrayList < Integer > inOrder;
        inOrder = inOrderTrav(root);

        System.out.println("The inOrder Traversal is : ");
        for (int i = 0; i < inOrder.size(); i++) {
            System.out.print(inOrder.get(i) + " ");
        }
    }
}
