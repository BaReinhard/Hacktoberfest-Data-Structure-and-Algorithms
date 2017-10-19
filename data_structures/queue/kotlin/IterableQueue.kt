import java.util.NoSuchElementException

class IterableQueue<E> : Iterable<E> {
    private var first: Node<E>? = null    // beginning of queue
    private var last: Node<E>? = null     // end of queue
    private var n: Int = 0            // number of elements on queue

    // helper linked list class
    private class Node<E> {
        internal var element: E? = null
        internal var next: Node<E>? = null
    }

    /**
     * Initializes an empty queue.
     */
    init {
        first = null
        last = null
        n = 0
    }

    /**
     * Returns true if this queue is empty.

     * @return `true` if this queue is empty; `false` otherwise
     */
    val isEmpty: Boolean
        get() = first == null

    /**
     * Returns the number of items in this queue.

     * @return the number of items in this queue
     */
    fun size(): Int {
        return n
    }

    /**
     * Returns the element least recently added to this queue.

     * @return the element least recently added to this queue
     * *
     * @throws NoSuchElementException if this queue is empty
     */
    fun peek(): E {
        if (isEmpty) throw NoSuchElementException("Queue underflow")
        return first!!.element!!
    }

    /**
     * Adds the element to this queue.

     * @param  element the element to add
     */
    fun enqueue(element: E) {
        val oldLast = last
        last = Node<E>()
        last!!.element = element
        last!!.next = null
        if (isEmpty)
            first = last
        else
            oldLast!!.next = last
        n++
    }

    /**
     * Removes and returns the element on this queue that was least recently added.

     * @return the element on this queue that was least recently added
     * *
     * @throws NoSuchElementException if this queue is empty
     */
    fun dequeue(): E {
        if (isEmpty) throw NoSuchElementException("Queue underflow")
        val element = first!!.element
        first = first!!.next
        n--
        if (isEmpty) last = null   // to avoid loitering
        return element!!
    }

    /**
     * Returns a string representation of this queue.

     * @return the sequence of items in FIFO order, separated by spaces
     */
    override fun toString(): String {
        val s = StringBuilder()
        for (element in this) {
            s.append(element)
            s.append(' ')
        }
        return s.toString()
    }

    /**
     * Returns an iterator that iterates over the items in this queue in FIFO order.

     * @return an iterator that iterates over the items in this queue in FIFO order
     */
    override fun iterator(): Iterator<E> {
        return ListIterator(first)
    }

    // an iterator, doesn't implement remove() since it's optional
    private inner class ListIterator<Item>(private var current: Node<Item>?) : Iterator<Item> {

        override fun hasNext(): Boolean {
            return current != null
        }

        override fun next(): Item {
            if (!hasNext()) throw NoSuchElementException()
            val item = current!!.element
            current = current!!.next
            return item!!
        }
    }
}
