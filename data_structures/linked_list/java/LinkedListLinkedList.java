/**
 * Java LinkedList implementation for Hacktoberfest
 * @author Prohunt
 *
 * @param <E> type of LinkedList
 */
public class LinkedList<E> {
	private Node head;
	private Node tail;
	
	private int size;
	/**
	 * Constructor
	 */
	public LinkedList(){
		head = null;
		tail = null;
		size = 0;
	}
	/**
	 * Adds an element to the tail end of the list
	 * @param element
	 * @return success or failure
	 */
	public boolean add(E element){
		if(null == head){
			head = new Node(element);
			size++;
			return true;
		}
		if(null == tail){
			tail = new Node(element);
			head.next = tail;
			size++;
			return true;
		}
		if(null != element){
			tail.next = new Node(element);
			tail = new Node(element);
			size++;
			return true;
		}
		return false;
	}
	/**
	 * Removes the given element from the list
	 * @param element to remove
	 * @return success or failure
	 */
	public boolean remove(E element){
		Node current = head;
		while(null != current.next){
			if(current.next.data.equals(element)){
				current.next = current.next.next;
				size--;
				return true;
			}
			current = current.next;
		}
		return false;
	}
	
	/**
	 * Checks if the list contains the element
	 * @param element to check
	 * @return true if it contains it, false otherwise
	 */
	public boolean contains(E element) {
		Node current = head;
		while (null != current){
			if(current.data.equals(element)){
				return true;
			}
			current = current.next;
		}
		return false;
	}
	
	/**
	 * Get the Head of the list
	 * @return
	 */
	public E head(){
		return head.data;
	}
	
	/**
	 * Gets the tail of the list
	 * @return tail element
	 */
	public E tail(){
		return tail.data;
	}
	
	/**
	 * Gets the size of the list
	 * @return size
	 */
	public int size(){
		return size;
	}
	/**
	 * Inner Class for storing elements as nodes
	 * Provides a next Node for linking the elements together
	 * @author Prohunt
	 *
	 */
	private class Node{
		E data;
		Node next;
		
		
		public Node(E element){
			data = element;
			next = null;
		}

		

	
	}

}
