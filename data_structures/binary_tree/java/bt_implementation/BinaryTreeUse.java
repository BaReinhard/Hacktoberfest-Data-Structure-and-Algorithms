package binaryTrees;

import java.util.Scanner;
import sun.misc.Queue;

public class BinaryTreeUse {

	static Scanner s = new Scanner(System.in);

	public static BinaryTreeNode<Integer> buildBinaryTree(){
		System.out.println("Enter the root data: ");
		int rootdata = s.nextInt();
		BinaryTreeNode<Integer> root =  new BinaryTreeNode<Integer>(rootdata);
		Queue<BinaryTreeNode<Integer>> queue = new Queue<>();
		queue.enqueue(root);
		
		while(!queue.isEmpty()) {
			
			//The InterruptedException occurs here when we need to wait for the network to assign a value;
			//we can avoid throwing it by using try catch block;
			BinaryTreeNode<Integer> currentNode = null;
			try {
				currentNode = queue.dequeue();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
			System.out.println("Enter left of " + currentNode.data + ": ");
			int left = s.nextInt();
			if(left!=-1) {
				BinaryTreeNode<Integer> leftNode = new BinaryTreeNode<Integer>(left);
				currentNode.setLeft(leftNode);
				queue.enqueue(leftNode);
			}
			
			System.out.println("Enter right of " + currentNode.data + ": ");
			int right = s.nextInt();
			if(right!=-1) {
				BinaryTreeNode<Integer> rightNode = new BinaryTreeNode<Integer>(right);
				currentNode.setRight(rightNode);
				queue.enqueue(rightNode);
			}

		}
		return root;
	}
	
	//Need to resolve this method
	public static void printBinaryTree(BinaryTreeNode<Integer> root) {
		if(root == null) {
			return;
		}
		System.out.println(root.data);
		printBinaryTree(root.left);
		printBinaryTree(root.right);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BinaryTreeNode<Integer> root = buildBinaryTree();
		printBinaryTree(root);
		
	}

}
