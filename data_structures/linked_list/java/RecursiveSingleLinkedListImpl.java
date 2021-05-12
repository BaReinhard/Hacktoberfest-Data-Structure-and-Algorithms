package adt.linkedList;

public class RecursiveSingleLinkedListImpl<T> implements LinkedList<T> {

	protected T data;
	protected RecursiveSingleLinkedListImpl<T> next;

	public RecursiveSingleLinkedListImpl() {

	}

	public RecursiveSingleLinkedListImpl(T data,
			RecursiveSingleLinkedListImpl<T> next) {
		this.data = data;
		this.next = next;
	}

	@Override
	public boolean isEmpty() {
		return this.data == null;
	}

	@Override
	public int size() {
		if(isEmpty()) {
			return 0;
		}
		else {
			return 1 + next.size();
		}
	}

	@Override
	public T search(T element) {
		if (element != null){
			if(isEmpty()) return null;
			else {
				if(this.data == element) return element;
				else return next.search(element);
			}
		}
		return null;
	}

	@Override
	public void insert(T element) {
		if(element != null){
			if(isEmpty()) {
				this.data = element;
				this.next = new RecursiveSingleLinkedListImpl<T>();
			} else next.insert(element);
		}
	}

	@Override
	public void remove(T element) {
		if(element == null) return;
		if(isEmpty()) return;
		if(this.data == element) {
			this.data = next.data;
			this.next = next.next;
		}
		else {
			next.remove(element);
		}
	}

	@SuppressWarnings("unchecked")
	@Override
	public T[] toArray() {
		T[] array = (T[]) new Object[this.size()];
		toArrayHelper(array, this, 0);
		return array;
		
	}
	
	public void toArrayHelper(T[] array, RecursiveSingleLinkedListImpl<T> node, int i) {
		if(!node.isEmpty()) {
			array[i] = node.data;
			toArrayHelper(array, node.next, ++i);
		}
	}
	
	public T getData() {
		return data;
	}

	public void setData(T data) {
		this.data = data;
	}

	public RecursiveSingleLinkedListImpl<T> getNext() {
		return next;
	}

	public void setNext(RecursiveSingleLinkedListImpl<T> next) {
		this.next = next;
	}
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

package adt.linkedList;

/**
 * The interface of a generic linked list.
 */
public interface LinkedList<T> {
	/**
	 * @return true if the list is empty or false, otherwise
	 */
	public boolean isEmpty();

	/**
	 * @return the number of elements on the list
	 */
	public int size();

	/**
	 * Searches for a given element in the list.
	 * 
	 * @param element
	 *            the element being searched for
	 * @return the element if it is in the list or null, otherwise
	 */
	public T search(T element);

	/**
	 * Inserts a new element at the end of the list. Null elements must be
	 * ignored.
	 * 
	 * @param element
	 *            the element to be inserted
	 */
	public void insert(T element);

	/**
	 * Removes an element from the list. If the element does not exist the list
	 * is not changed.
	 * 
	 * @param element
	 *            the element to be removed
	 */
	public void remove(T element);

	/**
	 * Returns an array containing all elements in the structure. The array does
	 * not contain empty spaces (or null elements). The elements are put into
	 * the array from the beginning to the end of the list.
	 * 
	 * @return an array containing all elements in the structure in the order
	 *         they appear
	 */
	public T[] toArray();
}
