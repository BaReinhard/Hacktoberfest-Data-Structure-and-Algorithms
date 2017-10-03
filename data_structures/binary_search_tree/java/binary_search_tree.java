
/*
** Binary tree & Binary tree search implementation in java
*/


/*
**Input patterns 
**create 25 15 9 18 2 90 25 42 60 35 1 19 10 100 3 - create the binary tree
**print - print the binary tree in sorted order
**search 15 
**delete 15
**search 15
**search 13
**add 13
**search 13
**pre-order
**in-order
**post-order
**
**
*/


import java.util.Scanner;
import java.util.LinkedList;

class Node {                                                                    //create a Node class

    private int value;
    private Node left;
    private Node right;

    public Node getLeft() {
        return this.left;
    }

    public void setLeft(Node e) {
        this.left = e;
    }

    public Node getRight() {
        return this.right;
    }

    public void setRight(Node e) {
        this.right = e;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public int getValue() {
        return this.value;
    }
}

/**
 *
 * @author Thuvarakan
 */


public class BinarySearchTree {

    public static void main(String[] args){

    	Scanner scanner = new Scanner(System.in);
        BinSearchTree th = new BinSearchTree();
        Node root = null;
        String line;
        while ((line = scanner.nextLine() )!= null) {
            String[] tokens = line.split(" ");
            //check the instructions
            switch (tokens[0]) {
                //if instruction is create
                case "create": {

                    int[] a = new int[tokens.length - 1];
                    for (int i = 0; i < a.length; i++) {
                        a[i] = Integer.parseInt(tokens[i + 1]);
                    }
                    root = th.createTree(a);
                    if (root != null) {
                        System.out.println("S");
                    } else {
                        System.out.println("F");
                    }
                    break;
                }
                //if instruction is print
                case "print":
                    th.print_tree(root);
                    break;
                //if instruction is search
                case "search":
                    if (th.searchValue(root, Integer.parseInt(tokens[1])) != null) {
                        System.out.println("T");
                    } else {
                        System.out.println("F");
                    }
                    break;
                //if instruction is delete
                case "delete":
                    if (th.deleteValue(root, Integer.parseInt(tokens[1]))) {
                        System.out.println("S");
                    } else {
                        System.out.println("F");
                    }
                    break;
                //if instruction is add
                case "add":
                    if (th.addValue(root, Integer.parseInt(tokens[1]))) {
                        System.out.println("S");
                    } else {
                        System.out.println("F");
                    }
                    break;
                //if instruction is pre-order
                case "pre-order":
                    th.traverse_preorder(root);
                    System.out.println();
                    break;
                //if instruction is in-order
                case "in-order":
                    th.traverse_inorder(root);
                    System.out.println();
                    break;
                //if instruction is post-order
                case "post-order":
                    th.traverse_postorder(root);
                    System.out.println();
                    break;
            }
        }
    }
}

class Bintree {

    public boolean addLeftChild(Node parent, int newvalue) {                   //add left child for binary tree
        if (parent.getLeft() == null) {
            parent.setLeft(new Node());
            parent.getLeft().setValue(newvalue);
            return true;
        }
        return false;
    }

    public boolean addRightChild(Node parent, int newvalue) {                  //add right child for binary tree
        if (parent.getRight() == null) {
            parent.setRight(new Node());
            parent.getRight().setValue(newvalue);
            return true;
        }
        return false;
    }

    public Node createTree(int[] elements) {                               //create a new tree
        LinkedList<Node> lisa = new LinkedList<>();
        Node root = new Node();
        Node root1 = root;
        root.setValue(elements[0]);
        lisa.addLast(root);
        int i = 1;
        while (!lisa.isEmpty()) {
            root = lisa.removeFirst();
            if (i < elements.length) {
                this.addLeftChild(root, elements[i]);
                lisa.addLast(root.getLeft());
                i++;
                if (i < elements.length) {
                    this.addRightChild(root, elements[i]);
                    lisa.addLast(root.getRight());
                    i++;
                }
            } else {
                return root1;
            }
        }
        return root1;
    }

    public boolean expandTree(Node root, int[] elements) {             //expand tree
        LinkedList<Node> nodeList = new LinkedList<>();                 //create a linkedlist
        nodeList.addLast(root);
        int i = 0;
        while (!nodeList.isEmpty()) {                                   //run until finish all array elements 
            root = nodeList.removeFirst();
            if (i < elements.length) {
                if (root.getLeft() == null) {
                    this.addLeftChild(root, elements[i]);
                    nodeList.addLast(root.getLeft());
                    i++;
                } else {
                    nodeList.addLast(root.getLeft());
                }
                if (i < elements.length) {
                    if (root.getRight() == null) {
                        this.addRightChild(root, elements[i]);
                        nodeList.addLast(root.getRight());
                        i++;
                    } else {
                        nodeList.addLast(root.getRight());
                    }
                }
            } else {
                return true;
            }
        }
        return false;
    }

    public void traverse_inorder(Node root) {                      //inorder traversal
        if (root != null) {
            traverse_inorder(root.getLeft());
            System.out.print(root.getValue() + " ");
            traverse_inorder(root.getRight());
        }
    }

    public void traverse_preorder(Node root) {                     //inorder traversal
        if (root != null) {
            System.out.print(root.getValue() + " ");
            traverse_preorder(root.getLeft());
            traverse_preorder(root.getRight());
        }
    }

    public void traverse_postorder(Node root) {                    //postorder traversal
        if (root != null) {
            traverse_postorder(root.getLeft());
            traverse_postorder(root.getRight());
            System.out.print(root.getValue() + " ");
        }
    }
}

class BinSearchTree extends Bintree {                                  //create binary search tree

    public Node insert(Node root, int key) {                    //define a insert method
        //recursivly check and add the value in the correct place
        if (root == null) {
            root = new Node();
            root.setValue(key);
        } else if (key < root.getValue()) {
            root.setLeft(insert(root.getLeft(), key));
        } else {
            root.setRight(insert(root.getRight(), key));
        }
        return root;
    }

    @Override
    public Node createTree(int[] p) {                   //create Binary search tree
        Node thua = null;
        Node roots = null;
        for (int i = 0; i < p.length; i++) {
            thua = this.insert(thua, p[i]);
            if (i == 0) {
                roots = thua;
            }
        }
        return roots;
    }

    public boolean addValue(Node root, int newvalue) { //add value to the binary search tree
        if (this.searchValue(root, newvalue) == null) {
            if (root == null) {
                root = new Node();
                root.setValue(newvalue);
            } else if (newvalue < root.getValue()) {
                root.setLeft(insert(root.getLeft(), newvalue));
            } else {
                root.setRight(insert(root.getRight(), newvalue));
            }
            return true;
        }
        return false;
    }

    public boolean deleteValue(Node root, int value) {                 //delete a given value from tree
        Node parentNode = root;
        Node deleteNode;
        Node replaceNode;
        if (root == null) {
            return false;
        }
        if (this.searchValue(root, value) == null) {                        //Checks whether a given value exists
            return false;
        }
        deleteNode = root;
        //get the node being deleted & its parent Node
        while (deleteNode != null && deleteNode.getValue() != value) {
            parentNode = deleteNode;
            if (value < deleteNode.getValue()) {
                deleteNode = deleteNode.getLeft();
            } else if (value > deleteNode.getValue()) {
                deleteNode = deleteNode.getRight();
            }
        }

        if (deleteNode.getLeft() == null && deleteNode.getRight() == null) {          //when delete node don't has any child node
            if (parentNode.getLeft() == deleteNode) {
                parentNode.setLeft(null);
                return true;
            } else {
                parentNode.setRight(null);
                return true;
            }
        }
        if (deleteNode.getLeft() != null && deleteNode.getRight() == null) {          // when it has only a left child
            if (parentNode.getLeft() == deleteNode) {
                parentNode.setLeft(deleteNode.getLeft());
                return true;
            } else {
                parentNode.setRight(deleteNode.getLeft());
                return true;
            }
        }
        if (deleteNode.getLeft() == null && deleteNode.getRight() != null) {           // when it has only a right child
            if (parentNode.getLeft() == deleteNode) {
                parentNode.setLeft(deleteNode.getRight());
                return true;
            } else {
                parentNode.setRight(deleteNode.getRight());
                return true;
            }
        }
        if (deleteNode.getLeft() != null && deleteNode.getRight() != null) {          //when it has two child nodes
            parentNode = deleteNode;
            replaceNode = deleteNode.getRight();
            if (replaceNode.getLeft() == null) {
                deleteNode.setValue(replaceNode.getValue());
                deleteNode.setRight(replaceNode.getRight());
                return true;
            }
            //find the replace node and its parent
            while (replaceNode.getLeft() != null) {
                parentNode = replaceNode;
                replaceNode = replaceNode.getLeft();
            }
            deleteNode.setValue(replaceNode.getValue());
            parentNode.setLeft(replaceNode.getRight());
            return true;
        }
        return false;
    }

    public Node searchValue(Node root, int key) {          //find the node of the given value 
        Node refNode = root;
        while (refNode != null) {                 //get the node of the key value
            if (key == refNode.getValue()) {
                return refNode;
            } else if (key < refNode.getValue()) {
                refNode = refNode.getLeft();
            } else {
                refNode = refNode.getRight();
            }
        }
        return null;
    }

    public void print_tree(Node root) {
        this.traverse_inorder(root); //print binary search tree in sorted order
        System.out.println();
    }
}
