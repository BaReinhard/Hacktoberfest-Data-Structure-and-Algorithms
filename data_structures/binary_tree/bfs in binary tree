package shubham;  //Breadth first search to search the element and print the path.

import java.util.LinkedList;
import java.util.Queue;

public class bfs {

	public void levelOrderQueue(Node root) {
	Queue<Node> q = new LinkedList<Node>();
	if (root == null)
	return;
	q.add(root);
	while (!q.isEmpty()) {
	Node n = (Node) q.remove();
				
				
	int goal=11;
	int c=0;
				
				if (n.left != null)
					q.add(n.left);
				c+=1;
				if (n.right != null)
					q.add(n.right);
				c+=1;
				  System.out.print(" " + n.data);
					if(n.data==goal)
					break;
			
			    
			      
			    
			}
			
		}

		public static void main(String[] args) throws java.lang.Exception {
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
			
            bfs i = new bfs();
			System.out.println("Breadth First Search : ");
			i.levelOrderQueue(root);
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

