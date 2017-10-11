import java.util.Scanner;

//Create a node class for creating new nodes in linked list
class Node{
	
	private int data ; // data of that node
	private Node next ; // node data of next linked node
	private Node prev ; // node data of previous linked node
	 
	public Node() {  // initialize new node
		data = 0 ;
		next = null ;
		prev = null ;
	}
	
	// Input data in new node
	public Node(int d) {
		data = d ;
	}
	
	// set link to the next node
	public void setNextLink(Node link) {
		next = link ;
	}
	
	// set link to the previous node
	public void setPrevLink(Node link) {
		prev = link ;
	}
	
	// Get link of the next node
	public Node getNextLink() {
		return next ;
	}
	
	// Get link of the previous node
	public Node getPrevLink() {
		return prev ;
	}
	
	// Get data of the current node
	public int getData() {
		return data ;
	}
	
}

	//class for creating linked list
	class LinkList{
	
		private Node start ;
		private Node end ;
		public int size ;
		
		// Initialize all the variables
		public LinkList() {
			start = null ;
			end = null ;
			size = 0 ;
		}
		
		// Adding nodes at starting of the linked list
		public void addAtStart(int data) {
			
			Node node = new Node(data); // Create object of Node class
			size++ ; // Increment size of linked list
			
			if(start == null) {
				start = node ; // make start the current node
				start.setNextLink(null);
				start.setPrevLink(null);
				end = start ; // make node the ending node
			}else {
				
				start.setPrevLink(node); // Attach new node before start
				node.setNextLink(start); // Set start to the next of the node
				node.setPrevLink(null);
				start = node ; // make the new node as start
			}
			
		}
		
		public void addAtEnd(int data) {
			
			Node node = new Node(data);
			size++ ;
			
			if(start == null) {
				start = node ;
				start.setNextLink(null);
				start.setPrevLink(null);
				end = start ;
			}else {
				
				end.setNextLink(node); // Attach new node after end
				node.setPrevLink(null);
				node.setPrevLink(end); // Set end to the previous of the node
				end = node ; // make the new node as end
			}
			
		}
		
		// Adding node at the middle of the linked list
		public void addAtMiddle(int data , int pos) {
			Node node = new Node(data);
			size++ ;
			
			Node preptr = start ;
			Node ptr = start ;
			ptr = ptr.getNextLink();
			int count = 1 ;
			while(count != pos) {
				preptr = preptr.getNextLink();
				ptr = ptr.getNextLink();
				count++ ;
			}
			preptr.setNextLink(node);
			node.setPrevLink(preptr);
			node.setNextLink(ptr);
			ptr.setPrevLink(node);
			
		}
		
		// Adding node after a certain data of the linked list
		public void addAfterData(int data , int refData) {
			Node node = new Node(data);
			size++ ;
			
			
			Node preptr = start ;
			Node ptr = start ;
			ptr = ptr.getNextLink();
			
			while(preptr.getData() != refData) {
				preptr = preptr.getNextLink();
				ptr = ptr.getNextLink();
			}
			preptr.setNextLink(node);
			node.setPrevLink(preptr);
			node.setNextLink(ptr);
			ptr.setPrevLink(node);
			
		}
		
		// Deleting node in linked list
		public void deleteNode(int refData) {
			
			Node preptr = start ;
			Node ptr = start ;
			ptr = ptr.getNextLink();
			
			while(ptr.getData() != refData) {
				preptr = preptr.getNextLink();
				ptr = ptr.getNextLink();
			}
			
			preptr.setNextLink(ptr.getNextLink());
			ptr.getNextLink().setPrevLink(preptr);
			ptr = null ;
			
			size-- ; // Reduce size of linked list
			
		}
		
		// Traversing data from left to right 
		public void showDataFromLeft() {
			
			Node ptr = start ;
			
			while(ptr.getNextLink()!=null) {
				System.out.print(ptr.getData() + "-->");
				ptr = ptr.getNextLink();
			}
			System.out.print(ptr.getData());
			
		}
		
		// Traversing data from right to lest 
		public void showDataFromRight() {
			
			Node ptr = end ;
			
			while(ptr.getPrevLink()!=null) {
				System.out.print(ptr.getData() + "-->");
				ptr = ptr.getPrevLink();
			}
			System.out.print(ptr.getData());
			
		}
	
	}


public class DoublyLinkedList {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int data = 0 ;
		
		LinkList ll = new LinkList();
		
		System.out.println("Choose : \n1. Insert at Start \n2. Insert At End ");
		
		switch (sc.nextInt()) {
		case 1:
			// Get data from user again and again and add them to linked list
			do {
				System.out.print("Enter the data : ");
				data = sc.nextInt();
				
				ll.addAtStart(data);
				
				System.out.print("Do you want to add more (y/n) : ");
				
			}while(sc.next().equals("y"));
			
			System.out.println("From left to right : ");
			ll.showDataFromLeft(); // show data from left to right of linked list
			System.out.println("\nFrom right to left : ");
			ll.showDataFromRight(); // show data from right to left of linked list
			
			break;
			
		case 2:
			
			do {
				System.out.print("Enter the data : ");
				data = sc.nextInt();
				
				ll.addAtEnd(data);
				
				System.out.print("Do you want to add more (y/n) : ");
				
			}while(sc.next().equals("y"));
			
			System.out.println("From left to right : ");
			ll.showDataFromLeft();
			System.out.println("\nFrom right to left : ");
			ll.showDataFromRight();
			
			break;

		default:
			break;
		}
		
		System.out.println("\nChoose : \n1. Insert At Middle \n2. Insert After A Data \n3. Delete A Node");
		
		switch (sc.nextInt()) {
		case 1:
			System.out.print("Enter the data : ");
			data = sc.nextInt();
			int pos = 0 ;
			if(ll.size%2 == 0) {
				pos = ll.size/2 ;
			}else {
				pos = (ll.size - 1)/2 ;
			}
			
			ll.addAtMiddle(data , pos);
			// Calculating middle position
			System.out.println("From left to right : ");
			ll.showDataFromLeft();
			System.out.println("\nFrom right to left : ");
			ll.showDataFromRight();
			
			break;
		case 2:
			System.out.print("Enter the data : ");
			data = sc.nextInt();
			
			System.out.print("Enter the data after which you want to add new data : ");
			
			ll.addAfterData(data , sc.nextInt());
			
			System.out.println("From left to right : ");
			ll.showDataFromLeft();
			System.out.println("\nFrom right to left : ");
			ll.showDataFromRight();
			
			break;
		case 3:
			System.out.print("Enter the data to be deleted : ");
			data = sc.nextInt();
			
			ll.deleteNode(data); // Delete node
			
			System.out.println("From left to right : ");
			ll.showDataFromLeft();
			System.out.println("\nFrom right to left : ");
			ll.showDataFromRight();
			
			break;

		default:
			break;
		}

		
	}

}
