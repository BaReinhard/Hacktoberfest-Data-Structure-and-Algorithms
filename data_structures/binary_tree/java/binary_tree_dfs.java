import java.util.*;

class Node{
	int data;
	Node left,right;

		public Node(int item){
		data = item;
		left = right = null;
		}

}

class BinaryTree{

	Node root;
	BinaryTree(){
	root = null;
}


public void preorder_rec(Node node){

	if(node == null) return;
	System.out.println(node.data);

	preorder_rec(node.left);

	preorder_rec(node.right);

}



public void inorder_rec(Node node){

	if(node == null) return;

	inorder_rec(node.left);

	System.out.println(node.data);

	inorder_rec(node.right);

}



public void postorder(Node node){

	if(node == null) return;
	postorder(node.left);

	postorder(node.right);

	System.out.println(node.data);

}



public static void main(String[] args){

BinaryTree bt = new BinaryTree();

 bt.root = new Node(1);
 bt.root.left = new Node(2);
 bt.root.right = new Node(3);
 bt.root.left.left = new Node(4);
 bt.root.left.right = new Node(5);  
 bt.root.right.right = new Node(7);
 bt.root.right.left = new Node(6);
 bt.queue.add(bt.root);


System.out.println("Preorder Recursive");
bt.preorder_rec(bt.root);

System.out.println("Inorder Recursive");
bt.inorder_rec(bt.root);

System.out.println("Postorder");
bt.postorder(bt.root);



}

}