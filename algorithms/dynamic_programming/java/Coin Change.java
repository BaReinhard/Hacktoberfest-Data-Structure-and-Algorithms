import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr  = new int[n];
        for(int i=0;i<n;i++)
            arr[i]=scn.nextInt();
            
        int target = scn.nextInt();
        System.out.println(coinchange(arr,target));
        
    }
    
    
    public static int coinchange(int[] arr, int tar){
        
      int[] dp = new int[tar+1];
      dp[0]=1;
      
      for(int i=0;i<arr.length;i++){
          int val = arr[i];
          
          for(int j=val;j<dp.length;j++){
              if(dp[j-val]!=0){
                  dp[j]+=dp[j-val];
              }
          }
      }
      
      return dp[tar];
        
        
    }
}