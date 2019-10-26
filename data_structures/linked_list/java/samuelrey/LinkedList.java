import java.lang.IndexOutOfBoundsException;

public class LinkedList<T> {

    private Node<T> head;
    private Node<T> tail;
    private int count;

    public LinkedList() {
        head = null;
        tail = null;
        count = 0;
    }

    public void insert(T data) {
        if(count == 0) {
            head = new Node(data);
            tail = head;
        }

        else {
            tail.next = new Node(data);
        }

        count++;
    }

    public void remove(int index) {
        if(index < 0 || index >= count) {
            throw new IndexOutOfBoundsException();
        }

        if(index == 0) {
            if(head == tail) {
                tail = null;
            }
            head = head.next;
        }

        else {
            Node<T> tmp = head;
            while(index > 1) {
                tmp = tmp.next;
                index--;
            }
            if(tmp.next == tail) {
                tmp.next = null;
            }
            else {
                tmp.next = tmp.next.next;
            } 
        }

        count--;
    }

    public T get(int index) {
        if(index < 0 || index >= count) {
            throw new IndexOutOfBoundsException();
        }

        Node<T> tmp = head;
        while(index > 0) {
            tmp = tmp.next;
        }

        return tmp.data;
    }

    private class Node<T> {
        public T data;
        public Node<T> next;

        public Node(T data) {
            this.data = data;
            this.next = null;
        }
    }
}
