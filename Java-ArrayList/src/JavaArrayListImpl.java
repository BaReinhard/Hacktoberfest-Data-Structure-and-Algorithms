import java.util.ArrayList;

public class JavaArrayListImpl {

	public static void main(String[] args) {

		// Created arraylist
		ArrayList<String> list = new ArrayList<String>();

		// Adding elements
		list.add("A");
		list.add("B");
		list.add("C");
		list.add("D");
		list.add("E");
		list.add("F");

		// Printing size
		System.out.println("List Size: " + list.size());

		// Printing contents
		for (String str : list)
			System.out.println(str);

		// Removing first 2 elements
		list.remove(0);
		list.remove(1);

		// Printing size after removing first 2 elements
		System.out.println("List Size: " + list.size());

		// Printing contents after removing first 2 elements
		for (String str : list)
			System.out.println(str);
	}

}
