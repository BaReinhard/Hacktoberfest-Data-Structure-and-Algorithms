import java.util.*;

public class ArrayListImplementor {
    public static void main(String... args) {
        //create an heterogenous array list
        ArrayList arrayList = new ArrayList();
        System.out.println("Initial size of al: " + arrayList.size());

        //append elements to array list
        arrayList.add("C");
        arrayList.add("A");
        arrayList.add("E");
        arrayList.add("B");
        arrayList.add("D");
        arrayList.add("F");
        arrayList.add(4);

        //insert elements at position 5 and 1 respectively
        arrayList.add(5, 7.9);
        arrayList.add(1, "A2");
        System.out.println("Size of al after additions: " + arrayList.size());

        // display the array list
        System.out.println("Contents of array list: " + arrayList);

        // Remove elements from the array list using value and position respectively.
        arrayList.remove("F");
        arrayList.remove(2);
        System.out.println("Size of al after deletions: " + arrayList.size());

        //display array list elements
        System.out.println("Elements of array list: ");
        for (int count = 0; count < arrayList.size(); count++) {
            System.out.print(arrayList.get(count) + " ");
        }
        System.out.println("");

        //creating a arraylist comprising of elements belonging to same type
        ArrayList<String> stringArrayList = new ArrayList<>();

        //append elements to array list
        stringArrayList.add("String1");
        stringArrayList.add("String2");

        //all the other functions of arraylist will be implemented in same order, however trying to add element as stringArrayList.add(4) will throw error

        //display string arraylist elements
        System.out.println("Contents of string array list: ");
        for (String element :
                stringArrayList) {
            System.out.print(element + " ");
        }
        System.out.println("");
    }
}