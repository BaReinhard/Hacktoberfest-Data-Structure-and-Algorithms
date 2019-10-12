package bst_operations;

import java.util.ArrayList;

/**
 * Created by kalsi on 30/08/17.
 * Path from root to node
 */
public class PathFromRootToNode {
    Boolean found = false;
    public static void main(String[] args) {
        new PathFromRootToNode().demo();
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
        ArrayList<Node> al = new ArrayList<Node>();
        findPath(n, 13, al);
        display(al);

    }

    private void display(ArrayList<Node> al) {
        System.out.println("--");
        for (Node n : al) {
            System.out.print(n.data + " --> ");
        }
        System.out.println("NULL");
    }

    private void findPath(Node n, int data, ArrayList<Node> al) {
        if (n != null && !found) {
            al.add(n);
            findPath(n.left, data, al);
            if (n.data == data) {
                found = true;
            }
            findPath(n.right, data, al);
            if (!found) {
                al.remove(al.size() - 1);
            }
        }
    }
}
