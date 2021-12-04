import  java.lang.*;

public class LinkedListShorter {

    class Node {

        int key;
        Node next;

        public Node (int key){
            this.key = key;
        }

        public void print() {
            System.out.println ("Key: " + key);
            System.out.println ("Next: " + next);
        }
    }

    Node head;

    public List (Node head){
        this.head = head;
    }

    public boolean isEmpty(){
        return head.next == null;
    }

    public boolean exists (int key) {
        Node current = head;
        while (current != null){
            if (current.key == key) return true;
            current = current.next;
        }
        return false;
    }

    public void insertAtHead (Node toInsert){
        toInsert.next = head.next;
        head.next = toInsert;
    }

    public void insertAtTail (Node toInsert){
        Node current = head;
        while (current.next != null){
            current = current.next;
        }
        current.next = toInsert;
        toInsert.next = null;
    }

    public void insertAfterKey (int key, Node toInsert){
        Node current = head;
        if (!exists(key)) System.out.println ("Key not found.");
        else {
            while (current.key != key){
                current = current.next;
            }
            toInsert.next = current.next;
            current.next = toInsert;
        }
    }

    public Node getElement(int pos){
        Node current = head;
        for (int i = 1; i <= pos; i++){
            current = current.next;
        }
        return current;
    }

    public int countElements (){
        Node current = head;
        int counter = 0;
        while (current != null){
            counter++;
            current = current.next;
        }
        return counter;
    }

    public void printList (){
        Node current = head;
        while (current != null){
            System.out.println ("Key:  " + current.key);
            if (current.next == null) System.out.println ("Last Node.");
            else System.out.println ("Next: " + current.next.key);
            current = current.next;
        }
        System.out.print (countElements() + " Elements in this List.");
    }
}