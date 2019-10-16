package bst_operations;


import java.util.*;

/**
 * Created by kalsi on 01/09/17.
 */
public class LevelOrder {
    public static void main(String[] args) {
        new LevelOrder().demo();
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
                        3                    10
                  1             6                       14
                           4        7              13
        *
        * */
        System.out.println("Without zigzag");
        displayLevelOrder(n, false); //without zigzag
        System.out.println("With zigzag");
        displayLevelOrder(n, true); //with zigzag
    }

    private void displayLevelOrder(Node n, Boolean zigzag) {
        if (n == null) {
            return;
        }
        Boolean flag = true;
        Deque<Node> parents = new LinkedList<Node>();
        parents.add(n);
        while (!parents.isEmpty()) {
            print(parents, flag, zigzag);
            flag = !flag;
            int count = parents.size();
            while (count-- > 0) {
                Node removedParent = parents.removeFirst();
                if (removedParent.left != null) {
                    parents.addLast(removedParent.left);
                }
                if (removedParent.right != null) {
                    parents.addLast(removedParent.right);
                }
            }
            System.out.println();
        }
    }

    private void print(Deque<Node> parents, Boolean flag, Boolean zigzag) {
        Iterator<Node> iterator = parents.descendingIterator();
        if (!zigzag || flag) {
            iterator = parents.iterator();
        }
        while (iterator.hasNext()) {
            System.out.print(iterator.next().data + "\t");
        }

    }
}
