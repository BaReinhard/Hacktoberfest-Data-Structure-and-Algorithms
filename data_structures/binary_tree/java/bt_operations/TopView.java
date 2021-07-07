package binaryTrees;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

import sun.misc.Queue;

public class TopView {

	public static Scanner s = new Scanner(System.in);
	
	public static void printTopView(BinaryTreeNode<Integer> root) {
		
		// Time complexity: O(n)
		// The logic is much similar to Level-order traversal of Binary tree
		if(root == null) {
			return;
		}
		//using HashSet to keep records of unique horizontal distances;
		HashSet<Integer> set = new HashSet<Integer>();
		Queue<TopViewNode> queue = new Queue();
		queue.enqueue(new TopViewNode(root, 0));
		
		TopViewNode temp=null;
		while(!queue.isEmpty()) {
			
			try {
				temp = queue.dequeue();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			if(!set.contains(temp.hd)) {
				set.add(temp.hd);
				System.out.print(temp.node.data + " ");
			}
			
			if(temp.node.left!=null) {
				queue.enqueue(new TopViewNode(temp.node.left, temp.hd-1));
			}
			
			if(temp.node.right!=null) {
				queue.enqueue(new TopViewNode(temp.node.right, temp.hd+1));
			}
			
		}
		
	}
	
	public static void printTopViewWithoutHelperClass(BinaryTreeNode<Integer> root) {
		
		//to keep track of unique horizontal distances
		HashSet<Integer> set = new HashSet<Integer>();
		
		//to avoid using any helper class
		Queue<TvNode> queue = new Queue();
		
		TvNode temp = null;
		queue.enqueue(new TvNode(root, 0));

		while(!queue.isEmpty()) {
			
			try {
				 temp = queue.dequeue();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			if(!set.contains(temp.hd)) {
				set.add(temp.hd);
				System.out.print(temp.node.data + " ");
			}
			
			if(temp.node.left!=null) {
				queue.enqueue(new TvNode(temp.node.left, temp.hd-1));
			}
			
			if(temp.node.right!=null) {
				queue.enqueue(new TvNode(temp.node.right, temp.hd+1));
			}	
		}
	}
	
	public static class TvNode {

		//helper class to print topView of a binary tree
		
		BinaryTreeNode<Integer> node;
		//horizontal distance
		int hd;
		
		public TvNode(BinaryTreeNode<Integer> node, int hd) {
			this.hd = hd;
			this.node = node;
		}
	}
	
	public static void main(String[] args) {
		
		//using s separate helper class TopViewNode
		printTopView(BinaryTreeUse.buildBinaryTree());
		
		//without using any helper class;
		printTopViewWithoutHelperClass(BinaryTreeUse.buildBinaryTree());

	}
	
}
