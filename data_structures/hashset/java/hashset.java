import java.util.*;
class hashset {

   public static void main(String args[]) {
      // Create a tree set
      HashSet hs = new HashSet();
     
      // Add elements to the tree set
      hs.add(3);
      hs.add(2);
      hs.add(3);
      hs.add(2);
      hs.add(1);
      hs.add(4);
      //HashSet is very helpful datastructure for avoid duplicatses and access elements in o(1) time completexity. In this datastructure order is not preserved.
      System.out.println(hs);// output will be {2,3,1,4}
   }
}