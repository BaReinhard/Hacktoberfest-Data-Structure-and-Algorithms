public class Test {
	
		static class Node {
	        int data;
	        Node next;
	        Node(int tmp) {data = tmp;}
	    }
	 
		//Printing the nodes present in the linkedlist
	    static void printLinkedList(Node head) {
	        while(head != null) {
	            System.out.print(head.data+" ");
	            head = head.next;
	        }
	    }
	 
	    static void deleteDuplicates(Node head) {
	        // copy head node to temp current node
	        Node curr = head;
	 
	        // Traverse the linked list
	        while(curr != null) {
	        	
	            // copy current node to temp node.
	            Node temp = curr;
	            /**
	             * Compare the current node with next nodes data and
	             * keep on continue comparing as long as current nodes
	             * data is matching with other nodes.
	             */
	           
	            while(temp != null && temp.data == curr.data) {
	                temp = temp.next;
	            }
	            /**
	             * Set current node next pointer to the node which has
	             * different data value.
	             */
	            curr.next = temp;
	            curr = curr.next;
	        }
	    }
	 
	    public static void main(String[] a) {
	 
	        Node n1 = new Node(10);
	        Node n2 = new Node(20);
	        Node n3 = new Node(20);
	        Node n4 = new Node(20);
	        Node n5 = new Node(30);
	        Node n6 = new Node(40);
	        Node n7 = new Node(40);
	        n1.next = n2;
	        n2.next = n3;
	        n3.next = n4;
	        n4.next = n5;
	        n5.next = n6;
	        n6.next = n7;
	 
	        System.out.print("Initial linked list data: ");
	        printLinkedList(n1);
	        deleteDuplicates(n1);
	        System.out.println();
	        System.out.print("Linked list data after removing duplicates: ");
	        printLinkedList(n1);

	}

}
