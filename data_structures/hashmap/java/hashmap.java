import java.util.*;
class hashmap {

   public static void main(String args[]) {
      // Create a hash map
      HashMap hm = new HashMap();
      
      // Put elements to the map
      hm.put(1, "one");
      hm.put(2, "two");
      hm.put(3,"three");
      hm.put(1,"ONE");
      hm.put(4,"four");
      //storing values in key-value pairs with unorder of keys, by eliminating duplicate keys
      System.out.println(hm);//1-ONE,2-two,3-three,4-four
   }
}