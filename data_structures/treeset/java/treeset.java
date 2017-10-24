import java.util.*;
class treeset {

   public static void main(String args[]) {
      // Create a tree set
      TreeSet ts = new TreeSet();
     
      // Add elements to the tree set
      ts.add(3);
      ts.add(2);
      ts.add(3);
      ts.add(2);
      ts.add(1);
      ts.add(4);
      //Treeset is very helpful datastructure for avoid duplicatses and maintain the values in sorted order 
      System.out.println(ts);// output will be {1,2,3,4}
   }
}