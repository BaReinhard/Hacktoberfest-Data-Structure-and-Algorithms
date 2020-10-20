// Refer to the complete problem statement here: https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0

#include<iostream>
using namespace std;

int lcs(string s1, string s2){
        int n1=s1.size(),n2=s2.size();
        int dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    if(s1[i-1]==s2[j-1])
                        dp[i][j] = max(dp[i][j], 1+dp[i-1][j-1]);
                }
            }
        }
        int res = dp[n1][n2];
}

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n1,n2;
	    cin>>n1>>n2;
	    string s1,s2;
	    cin>>s1>>s2;
	    cout<<lcs(s1,s2)<<endl;
	}
	return 0;
}
