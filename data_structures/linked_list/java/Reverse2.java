class LinkedList {
    static Node head; 
    static class Node { 
  
        int data; 
        Node next; 
  
        Node(int d) 
        { 
            data = d; 
            next = null; 
        } 
    } 
  
    // Function to reverse the linked list 
    Node reverse(Node node) 
    { 
        Node prev = null; 
        Node current = node; 
        Node next = null; 
        while (current != null) { 
            next = current.next; 
            current.next = prev; 
            prev = current; 
            current = next; 
        } 
        node = prev; 
        return node; 
    } 
  
    // prints content of double linked list 
    void printList(Node node) 
    { 
        while (node != null) { 
            System.out.print(node.data + " "); 
            node = node.next; 
        } 
    } 
  
    public static void main(String[] args) 
    { 
    //creating an instance of Linkedlist class
        LinkedList ll = new LinkedList(); 
        
       //adding elements to the linkedlist
        ll.head = new Node(10); 
        ll.head.next = new Node(20); 
        ll.head.next.next = new Node(30); 
        ll.head.next.next.next = new Node(40); 
        
       //printing the nodes in the linkedlist
        System.out.println("Given Linked list"); 
        ll.printList(head); 
        
        //reversing the linkedlist
        head = ll.reverse(head); 
        
        System.out.println(""); 
        System.out.println("Reversed linked list "); 
        ll.printList(head); 
    } 
} 
