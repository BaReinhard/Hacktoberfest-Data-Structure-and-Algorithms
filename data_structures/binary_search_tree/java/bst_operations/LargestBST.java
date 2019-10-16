package bst_operations;


/**
 * Created by kalsi on 06/09/17.
 */
public class LargestBST {
    class BSTCount {
        Boolean isBST;
        int count;
    }

    class BST {
        int max;
        Node n;

        public BST() {
            max = -1;
            n = null;
        }
    }

    public static void main(String[] args) {
        new LargestBST().demo();
    }

    private void demo() {
        Node n = new Node(50);
        // left
        n.left = new Node(30);
        n.left.left = new Node(5);
        n.left.right = new Node(20);

        //right
        n.right = new Node(60);
        n.right.left = new Node(45);
        n.right.right = new Node(70);
        n.right.right.left = new Node(65);
        n.right.right.right = new Node(80);
      /*    50
         /    \
        30       60
      /  \     /  \
     5   20   45    70
                  /  \
                65    80
                */
        largestBST(n);
    }

    private void largestBST(Node n) {
        BST bst = new BST();
        BSTCount bstCount = new BSTCount();
        largestBSTUtil(n, bst, bstCount);
        System.out.println("Largest BST: " + bst.n.data);
        System.out.println("Count: " + bst.max);
    }

    private void largestBSTUtil(Node n, BST bst, BSTCount bstCount) {
        if (n == null) {
            return;
        }
        isBST(n, bstCount);
        if (bstCount.isBST && bstCount.count > bst.max) {
            bst.max = bstCount.count;
            bst.n = n;
        }
        largestBSTUtil(n.left, bst, bstCount);
        largestBSTUtil(n.right, bst, bstCount);
    }

    private void isBST(Node n, BSTCount bstCount) {
        bstCount.count = 0;
        bstCount.isBST = false;
        bstCount.isBST = isBSTUtil(n, Integer.MIN_VALUE, Integer.MAX_VALUE, bstCount);
    }

    private Boolean isBSTUtil(Node n, int minValue, int maxValue, BSTCount c) {
        if (n == null) {
            return true;
        }
        if (minValue < n.data && n.data < maxValue) {
            c.count++;
            return isBSTUtil(n.left, minValue, n.data, c) && isBSTUtil(n.right, n.data, maxValue, c);
        }

        return false;
    }
}