//Bruteforce : HashMaps for char and counts
public boolean isAnagram(String s, String t) 
{
      if(s.length()!=t.length())
          return false;
      HashMap<Character,Integer> map=new HashMap<Character,Integer>();
      HashMap<Character,Integer> map1=new HashMap<Character,Integer>();
  
      for(int i=0;i<s.length();i++)
      {
          if(!map.containsKey(s.charAt(i)))
          map.put(s.charAt(i),1);
          else
          {
          int count=map.get(s.charAt(i));
          map.put(s.charAt(i),++count);
          }

          if(!map1.containsKey(t.charAt(i)))
          map1.put(t.charAt(i),1);
          else
          {
          int count=map1.get(t.charAt(i));
          map1.put(t.charAt(i),++count);
          }
      }
      if (map.equals(map1))
      return true;
      return false;
}

//Better : Use Auxiliary arrays with indices as alphabets

public boolean isAnagram(String s, String t) 
{
    int[] sArray = new int[26];
    int[] tArray = new int[26];
    if(s.length() != t.length())
        return false;
  
    for(int i=0; i <  s.length(); i++)
    {
        sArray[s.charAt(i) - 97]++;
        tArray[t.charAt(i) - 97]++;    
    }
    
    for(int i = 0; i < 26; i++)
    {
        if(sArray[i] !=  tArray[i] )
        {
            return false;
        }
    }
    return true;
}
