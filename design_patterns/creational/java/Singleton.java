/*
 * Singleton Design Pattern is a creational design pattern which restricts the object creation to one, 
 * no matter how many times we access the class.
 */

public final class Singleton {
	private static Singleton instance = null;

	private Singleton() {
	}

	public static synchronized Singleton getInstance() {
		return (instance != null) ? instance : (instance = new Singleton());
	}

}
