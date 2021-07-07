package binaryTrees;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class LevelOrderLinkedList {

	@SuppressWarnings("unchecked")
	private static ArrayList<Node<BinaryTreeNode>> buildLL(BinaryTreeNode<Integer> root) throws InterruptedException {

		Queue<BinaryTreeNode> q = new LinkedList<>();
		q.add(root);
		
		//This arrayList will contain all the LInkedlIsts of each levels by index+1;
		//here the node will contain the data of type BinaryTreeNode and pointer to next element of type Node.
		ArrayList<Node<BinaryTreeNode>> al = new ArrayList<>();
		
		//adding the root to arrayList first
		//Node<BinaryTreeNode> n = new Node(root);
		
		Node<BinaryTreeNode> head = null, tail = null, temp = null;
		q.add(null);
		
		//buildQueueLevelOrder(q, root);
		
		while(!q.isEmpty()) {
			
			BinaryTreeNode<Integer> currentNode = q.remove();
			if(currentNode == null) {
				al.add(head);
				head = null;
				tail = null;
				
			}else {
				//System.out.println(currentNode.data);
				if(head == null) {
					
					head = new Node(currentNode);
					tail = head;
				}else {					
					Node<BinaryTreeNode> newNode = new Node(currentNode);
					tail.next = newNode;
					tail = newNode;
				}
				
				
				//not we need to traverse the queue till null, and enqueue all the remaining elements of the tree
				Queue<BinaryTreeNode> qq = q;
				BinaryTreeNode<Integer> bb = currentNode;
				
				if(qq.peek() == null) {
					
					//add elements to the queue
					if(currentNode.left!=null) {
						q.add(currentNode.left);
					}
					
					if(currentNode.right != null) {
						q.add(currentNode.right);
					}
				}
				
				while(qq.peek()!=null) {
										
					//add elements to the queue
					if(bb.left!=null) {
						q.add(bb.left);
					}
					
					if(bb.right != null) {
						q.add(bb.right);
					}
					bb = q.peek();
					//qq.add(q.peek());
					qq.remove();
				}
				
				if((currentNode.left != null) && (currentNode.right != null)) {
				
					q.add(null);					
				}
				//System.out.println(q.size());
			}
		}		
		return al;
	}

	public static void printArrayList(ArrayList<Node<BinaryTreeNode>> al, int index) {
		
		if(index == al.size()) {
			return;
		}
		printLLatIndex(al.get(index));
		
		//on new line
		System.out.print(" ");
		printArrayList(al, ++index);
	}
	
	public static void printLLatIndex(Node<BinaryTreeNode> root){
		
		if(root == null) {
			return;
		}
		
		//This is to print the data of the data of the node,
		System.out.print(root.data.data);
		printLLatIndex(root.next);
	}

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		
		BinaryTreeNode<Integer> root = BinaryTreeUse.buildBinaryTree();
		printArrayList(buildLL(root), 0);
		
	}

}
