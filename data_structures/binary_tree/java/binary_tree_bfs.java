//package shubham;  //Breadth first search to search the element and print the path.

import java.util.LinkedList;
import java.util.Queue;
import java.util.List;
import java.util.ArrayList;

public class bfs {

	public List<Integer> levelOrderQueue(Node root, int toData) {
		List<Integer> result = new ArrayList<>();
		
		if (root == null)
			return result;
		
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);
		
		while (!q.isEmpty()) {
			Node n = q.remove();
			result.add(n.data);
			if(n.data == toData)
				break;
			
			if (n.left != null)
				q.add(n.left);
			if (n.right != null)
				q.add(n.right);
		}
		
		return result;
	}

	public static void main(String[] args) {
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		root.right.left = new Node(6);
		root.right.right = new Node(7);
		root.left.left.left= new Node(8);
		root.left.left.right= new Node(9);
		root.left.right.left=new Node(10);
		root.left.right.right=new Node(11);
		root.right.left.left=new Node(12);
		root.right.left.right=new Node(13);
		root.right.left.right= new Node(14);
		root.right.right.right= new Node(15);
		
		bfs instance = new bfs();
		List<Integer> order = instance.levelOrderQueue(root, 11);
		
		System.out.println("Breadth First Search: ");
		for (int r : order) {
			System.out.print(r + " ");
		}
		System.out.println();
	}
}

class Node {
	int data;
	Node left;
	Node right;

	public Node(int data) {
		this.data = data;
		this.left = null;
		this.right = null;
	}
}
