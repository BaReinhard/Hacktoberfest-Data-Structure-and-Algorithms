class stack_linkedlist{
    Node head = null;
    class Node{
        int data;
        Node next;
        Node(int d){
            data = d;
            next = null;
        }
    }
    void push (int d){
        Node p = new Node(d);
        p.next = head;
        head = p;
    }
    int pop(){
        int d = head.data;
        head = head.next;
        return d;
    }
    int peek(){
        return head.data;
    }
}