import java.lang.*; 
import java.util.*; 

public class PigeonHoleSort 
{ 
    public static void pigeonhole_sort(int inputArray[], 
                                           int n) 
    {
        int min = inputArray[0]; 
        int max = inputArray[0]; 
        int range, i, j, index;  
  
        for(int a=0; a<n; a++) 
        { 
            if(inputArray[a] > max) 
                max = inputArray[a]; 
            if(inputArray[a] < min) 
                min = inputArray[a]; 
        } 
  
        range = max - min + 1; 
        int[] hole = new int[range]; 
        Arrays.fill(hole, 0); 
  
        for(i = 0; i<n; i++) 
            hole[inputArray[i] - min]++; 
          
        index = 0; 
  
        for(j = 0; j<range; j++) 
            while(hole[j]-->0) 
                inputArray[index++]=j+min; 
  
    } 
  
    public static void main(String[] args) 
    { 
        PigeonHoleSort sort = new PigeonHoleSort(); 
        int[] inputArray = {52, 37, 3, 45, 93, 52, 81}; 
  
        System.out.print("Sorted Order is : "); 

        sort.pigeonhole_sort(inputArray,inputArray.length); 
     
        for(int i=0 ; i<inputArray.length ; i++) 
            System.out.print(inputArray[i] + " "); 
	System.out.print("\n");
    } 
}
