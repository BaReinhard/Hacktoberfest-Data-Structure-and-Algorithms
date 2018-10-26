#include<cmath>
using namespace std;
int lcs(char str1[],char str2[],int len1,int len2,int dp[][101]){
    for(int i=1;i<=len1;i++)
        for(int j=1;j<=len2;j++){
            if(str1[i-1]==str2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    return dp[len1][len2];
}

int main()
{
	int t;
	cin>>t;
	while(t-->0){
	   int len1,len2;
	   cin>>len1>>len2;
	   char str1[101],str2[101];
	   cin>>str1>>str2;
	   int dp[101][101];
	   for(int i=0;i<=len1;i++)
	     for(int j=0;j<=len2;j++)
	        dp[i][j] = 0;
	   
	   cout<<lcs(str1,str2,len1,len2,dp)<<endl;
    }
}