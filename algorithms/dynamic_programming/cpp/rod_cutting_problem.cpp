// problem from GFG

int maximizeTheCuts(int n, int x, int y, int z)
{
    int dp[n+1];
    dp[0] = 0;
    int a,b,c;
    int t = INT_MIN;
    
    for(int i=1;i<=n;i++){
       a = i>=x?dp[i-x]:t;
       b = i>=y?dp[i-y]:t;
       c = i>=z?dp[i-z]:t;
        dp[i] = 1 + max(a,max(b,c));
    }
    // cout<<INT_MIN<<endl;
    // cout<<dp[n]<<endl;
    if(dp[n]<0){
        return 0;
    }
    else{
        return dp[n];
    }
}
