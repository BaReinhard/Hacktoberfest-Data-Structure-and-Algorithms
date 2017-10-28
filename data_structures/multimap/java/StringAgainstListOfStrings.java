import java.util.HashMap;
import java.util.List;
import java.util.Map;

class StringAgainstListOfStrings {
   Map<String, List<String>> multiMap = new HashMap<String, List<String>>();

   public void addItem(String key, List<String> values){
      multiMap.put(key, values);
   }

   public List<String> getItem(String key){
      return multiMap.get(key);
   }

   public void deleteItem(String key){
      multiMap.remove(key);
   }
}