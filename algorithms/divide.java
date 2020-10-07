
// program for maximum subarray sum 

import java.util.*; 
  
class divide { 
  
    // Find the maximum possible sum in arr[]  
    // such that arr[m] is part of it 
    static int maxCrossingSum(int arr[], int l, 
                                int mx, int hg) 
    { 
        // this elements on left of mid. 
        int sum = 0; 
        int left_sum = Integer.MIN_VALUE; 
        for (int i = mx; i >= l; i--) 
        { 
            sum = sum + arr[i]; 
            if (sum > left_sum) 
            left_sum = sum; 
        } 
  
        // this elements on right of mid 
        sum = 0; 
        int right_sum = Integer.MIN_VALUE; 
        for (int i = mx + 1; i <= hg; i++) 
        { 
            sum = sum + arr[i]; 
            if (sum > right_sum) 
            right_sum = sum; 
        } 
  
        // Return sum of elements on left 
        // Return and right of mid 
        return left_sum + right_sum; 
    } 
  
    // Returns sum of maxium sum subarray  
    
    static int maxSubArraySum(int arr[], int l,  
                                      int hg) 
    { 
    //Only one element 
    if (l == hg) 
        return arr[l]; 
  
    // Find middle point 
    int mx = (l + hg)/2; 
  
    
   //  Maximum subarray sum in left half 
    // Maximum subarray sum in right half 
    // Maximum subarray sum such that the  
    
    return Math.max(Math.max(maxSubArraySum(arr, l, mx), 
                    maxSubArraySum(arr, mx+1, hg)), 
                    maxCrossingSum(arr, l, mx, hg)); 
    } 
  
    /* Driver program to test maxSubArraySum */
    public static void main(String[] args) 
    { 
    int arr[] = {-10, -13, 23, -10, -11, 8, 13, -17}; 
    int n = arr.length; 
    int max_sum = maxSubArraySum(arr, 0, n-1); 
      
    System.out.println("sum of contiguous subarray of elements : "+ 
                                         max_sum); 
    } 
} 

