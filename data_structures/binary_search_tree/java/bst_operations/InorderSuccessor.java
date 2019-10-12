package bst_operations;

public class InorderSuccessor {
    public static void main(String[] args) {
        new InorderSuccessor().demo();
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
        System.out.println(getNextSuccessor(n, new Node(8)));
    }

    private Integer getNextSuccessor(Node root, Node target) {
        if (root == null || target == null) {
            return null;
        }
        Boolean found = false;
        Node candidate = null;
        Node current = root;
        while (current != null) {
            if (current.data == target.data) {
                found = true;
                current = current.right;
            } else if (current.data > target.data) {
                candidate = current;
                current = current.left;
            } else {
                current = current.right;
            }
        }
        return found && candidate != null ? candidate.data : null;
    }
}
