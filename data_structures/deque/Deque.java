package Deque;

public class Deque<E> extends DoubleLinkedSequence<E>{

    private NodeSequenceDL lastNode;

    public Deque(){
        super();
        this.lastNode = null;
    }

    public Deque(Deque<E> d){
        super(d);
        if ( this.isEmpty() ) {
            this.lastNode = null;
        } else {
            NodeSequenceDL node = this.getNode(this.size);
            this.lastNode = node;
        }
    }
    public E getFront() {
        return this.firstNode.getValue();
    }

    public E getBack() {
        return this.lastNode.getValue();
    }

    public void insertFront(E e) {
        NodeSequenceDL newNode = new NodeSequenceDL(e);
        if(isEmpty()){
            this.lastNode = newNode;
        } else{
            this.firstNode.setPrevious(newNode);
            newNode.setNext(this.firstNode);
        }
        this.firstNode = newNode;
        this.size++;
    }

    public void insertBack(E e) {
        NodeSequenceDL newNode = new NodeSequenceDL(e);
        if(isEmpty()){
            this.firstNode = newNode;
        } else{
            this.lastNode.setNext(newNode);
            newNode.setPrevious(this.lastNode);
        }
        this.lastNode = newNode;
        this.size++;
    }

    public void removeFront() {
        this.firstNode = this.firstNode.getNext();
        this.firstNode.setPrevious(null);
        this.size--;
        if(this.size == 0){
            this.lastNode = null;
            this.firstNode = null;
        }
    }

    public void removeBack() {
        this.lastNode = this.lastNode.getPrevious();
        this.lastNode.setNext(null);
        this.size--;
        if(this.size == 0){
            this.firstNode = null;
            this.lastNode = null;
        }
    }
}
