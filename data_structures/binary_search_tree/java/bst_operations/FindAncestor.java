package bst_operations;

/**
 * Created by kalsi on 30/08/17.
 * find lowest ancestor of two items
 * I assumed both the elements are present in the tree
 */
public class FindAncestor {
    public static void main(String[] args) {
        new FindAncestor().demo();
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
        int m1 = 4;
        int m2 = 7;
        Node ancestor = lowestAncestor(n, m1, m2);
        System.out.println("Lowest ancestor is : " + ancestor.data);
        System.out.println("Distance from root to ancestor is: " + findDistance(n, ancestor));
    }

    private int findDistance(Node n, Node ancestor) {
        return findDistanceUtil(n,ancestor, 0);
    }

    private int findDistanceUtil(Node n, Node ancestor, int level) {
        if(n == null || ancestor == null) {
            return 0;
        }
        if(n.data == ancestor.data) {
            return level;
        }
        level++;
        return findDistanceUtil(n.left, ancestor, level) + findDistanceUtil(n.right, ancestor, level);

    }

    private Node lowestAncestor(Node n, int m1, int m2) {
        if (n == null) {
            return null;
        }
        if (n.data == m2 || n.data == m1) {
            return n;
        }
        Node left = lowestAncestor(n.left, m1, m2);
        Node right = lowestAncestor(n.right, m1, m2);
        if (left != null && right != null) {
            return n;
        }
        return left == null ? right : left;
    }


}
