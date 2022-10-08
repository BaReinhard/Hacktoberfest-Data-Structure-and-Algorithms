/**
 * find the frequency of element in arry; 
 *  arr = {2,33,4,4,54,3,2}
 * 
 * output : 
 * 2 ->2
 * 33->1
 * 4->2
 * 54->1
 * 3->1
 */


import java.util.HashMap;
import java.util.IdentityHashMap;
import java.util.Map;

public class FrequencyOfEachElementArray {
   public  static  void  PrintFri(int arr[]){
       Map<Integer , Integer> map = new HashMap<>();

       for (int i = 0; i < arr.length; i++) {
           if(map.containsKey(arr[i])){
               map.put(arr[i], map.get(arr[i]) + 1);
           }
           else {
               map.put(arr[i], 1);
           }
       }

       for(Map.Entry<Integer, Integer>  entry:  map.entrySet()){
           System.out.println(entry.getKey() + " " + entry.getValue());
       }
   }
    public static void main(String[] args) {
        int arr[] = {21,2,4,56,5,3,2,3,2,34,};
        PrintFri(arr);
    }
}
