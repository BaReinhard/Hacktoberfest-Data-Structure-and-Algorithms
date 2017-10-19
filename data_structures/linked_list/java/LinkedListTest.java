import static org.junit.Assert.*;

import org.junit.Test;

/**
 * Testing LinkedList
 * @author Prohunt
 *
 */
public class LinkedListTest {
	@Test
	public void testLinkedList(){
		LinkedList<Integer> intList = new LinkedList<Integer>();
		assertTrue(intList.add(1));
		assertTrue(intList.add(2));
		assertEquals(new Integer(1), intList.head());
		assertEquals(new Integer(2), intList.tail());
		assertTrue(intList.add(3));
		assertEquals(new Integer(3), intList.tail());
		assertEquals(3, intList.size());
		
		assertFalse(intList.add(null));
		
		assertTrue(intList.remove(new Integer(3)));
		assertFalse(intList.contains(new Integer(3)));
		assertEquals(2, intList.size());
		
		assertTrue(intList.contains(new Integer(2)));
		
		assertFalse(intList.remove(new Integer(3)));
	}
}
