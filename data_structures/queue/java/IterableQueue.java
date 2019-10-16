import java.util.Iterator;
import java.util.NoSuchElementException;

public class IterableQueue<E> implements Iterable<E> {
    private Node<E> first;    // beginning of queue
    private Node<E> last;     // end of queue
    private int n;            // number of elements on queue

    // helper linked list class
    private static class Node<E> {
        private E element;
        private Node<E> next;
    }

    /**
     * Initializes an empty queue.
     */
    public IterableQueue() {
        first = null;
        last  = null;
        n = 0;
    }

    /**
     * Returns true if this queue is empty.
     *
     * @return {@code true} if this queue is empty; {@code false} otherwise
     */
    public boolean isEmpty() {
        return first == null;
    }

    /**
     * Returns the number of items in this queue.
     *
     * @return the number of items in this queue
     */
    public int size() {
        return n;
    }

    /**
     * Returns the element least recently added to this queue.
     *
     * @return the element least recently added to this queue
     * @throws NoSuchElementException if this queue is empty
     */
    public E peek() {
        if (isEmpty()) throw new NoSuchElementException("Queue underflow");
        return first.element;
    }

    /**
     * Adds the element to this queue.
     *
     * @param  element the element to add
     */
    public void enqueue(E element) {
        Node<E> oldLast = last;
        last = new Node<E>();
        last.element = element;
        last.next = null;
        if (isEmpty()) first = last;
        else           oldLast.next = last;
        n++;
    }

    /**
     * Removes and returns the element on this queue that was least recently added.
     *
     * @return the element on this queue that was least recently added
     * @throws NoSuchElementException if this queue is empty
     */
    public E dequeue() {
        if (isEmpty()) throw new NoSuchElementException("Queue underflow");
        E element = first.element;
        first = first.next;
        n--;
        if (isEmpty()) last = null;   // to avoid loitering
        return element;
    }

    /**
     * Returns a string representation of this queue.
     *
     * @return the sequence of items in FIFO order, separated by spaces
     */
    public String toString() {
        StringBuilder s = new StringBuilder();
        for (E element : this) {
            s.append(element);
            s.append(' ');
        }
        return s.toString();
    }

    /**
     * Returns an iterator that iterates over the items in this queue in FIFO order.
     *
     * @return an iterator that iterates over the items in this queue in FIFO order
     */
    public Iterator<E> iterator()  {
        return new ListIterator<E>(first);
    }

    // an iterator, doesn't implement remove() since it's optional
    private class ListIterator<Item> implements Iterator<Item> {
        private Node<Item> current;

        public ListIterator(Node<Item> first) {
            current = first;
        }

        public boolean hasNext()  { return current != null;                     }
        public void remove()      { throw new UnsupportedOperationException();  }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = current.element;
            current = current.next;
            return item;
        }
    }
}
