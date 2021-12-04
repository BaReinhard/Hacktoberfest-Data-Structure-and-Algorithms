#include<iostream>
using namespace std;

int longestPalinSub(string str) {

         int n=str.size();
         
         int dp[n][n]={0};
         
         for(int l=0;l<n;l++)
        {
         for(int i=0;i<n-l;i++)
         {
         int j=l+i;
         
         if(i==j)
          
            dp[i][i]=1;
         
        else if(str[i]==str[j])
          
            dp[i][j]=dp[i+1][j-1]+2;
        
        else
          
            dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        
      }
      
   }
   
   return dp[0][n-1];
   
}
int main()
{
          string str;
          cin>>str;
         cout<< longestPalinSub(str);
}
