import java.util.*;
class treemap {

   public static void main(String args[]) {
      // Create a hash map
      TreeMap tm = new TreeMap();
      
      // Put elements to the map
      tm.put(1, "one");
      tm.put(2, "two");
      tm.put(3,"three");
      tm.put(1,"ONE");
      tm.put(4,"four");
      //storing values in key-value pairs with sorted order of keys, by eliminating duplicate keys
      System.out.println(tm);//1-ONE,2-two,3-three,4-four
   }
}