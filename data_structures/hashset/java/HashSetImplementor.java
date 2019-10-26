import java.util.*;

public class HashSetImplementor{

   public static void main(String args[]) {

      //Generic HashSet
      HashSet hashSet = new HashSet();
      hashSet.add(1);
      hashSet.add("String1");
      hashSet.add(1.4);

      //HashSet with only integer elements
      HashSet<Integer> integerHashSet = new HashSet<>();
     
      // Add elements to the tree set
      integerHashSet.add(3);
      integerHashSet.add(2);
      integerHashSet.add(3);
      integerHashSet.add(2);
      integerHashSet.add(1);
      integerHashSet.add(4);
      //HashSet is very helpful datastructure for avoid duplicatses and access elements in o(1) time completexity. In this datastructure order is not preserved.
      System.out.println(integerHashSet);

      System.out.println(hashSet);

   }
}