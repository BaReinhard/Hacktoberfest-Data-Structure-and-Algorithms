package psa.naloga5;

import psa.naloga5.Prim;
import junit.framework.TestCase;

/**
 * insert Public Tests to this class. Public tests are written by the Instructor
 * and may be used for grading projects. This source code is made available to
 * students.
 */

public class PublicTests extends TestCase {
	Prim mst;

	protected void setUp() throws Exception {
	}
	
	public void testCreate() {
		mst = new Prim(2);
		assertEquals(2, mst.data.length);
		assertEquals(2, mst.data[0].length);
		assertEquals(2, mst.data[1].length);
	}
	
	public void testInsertEdge() {
		mst = new Prim(2);
		mst.addEdge(0, 1, 2);
		
		assertEquals(2, mst.data[0][1]);
		assertEquals(2, mst.data[1][0]);
		assertEquals(0, mst.data[0][0]);
		assertEquals(0, mst.data[1][1]);
	}
	
}
