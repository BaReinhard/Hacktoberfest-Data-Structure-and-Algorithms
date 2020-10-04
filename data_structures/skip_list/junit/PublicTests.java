package psa.naloga3;

import psa.naloga3.SkipList;
import junit.framework.TestCase;

/**
 * insert Public Tests to this class. Public tests are written by the Instructor
 * and may be used for grading projects. This source code is made available to
 * students.
 */
public class PublicTests extends TestCase {

	private SkipList sl;
	
	private String text = "1 2 4 45 23 3 6 34 25 8 12 10 -21 -43 -22 100 105 -99 -67 13 99 -18 10453 19532 -2981 -21374 -91238 21341";
	
	protected void setUp() throws Exception {
		sl = new SkipList(64);
	}

	public void testUstvariSkiplist() {
		sl.insert(1);
		assertTrue(sl.search(1));
	}
	
	public void testVnosZeObstojecega() {
		sl.insert(2);
		assertFalse(sl.insert(2));
	}
	
	public void testVecElementov(){
		for (String i:text.split(" ")){
			sl.insert(Integer.parseInt(i));
		}
		assertTrue(sl.search(-21));
		assertTrue(sl.search(6));
		assertFalse(sl.search(7));
		assertTrue(sl.search(45));
		assertTrue(sl.search(-22));
		assertFalse(sl.search(-100));
		assertTrue(sl.search(8));
		assertFalse(sl.search(9));
		assertTrue(sl.search(12));
		assertFalse(sl.search(0));
		assertFalse(sl.search(-145));
		assertTrue(sl.search(1));
		assertTrue(sl.search(34));
	}
}
