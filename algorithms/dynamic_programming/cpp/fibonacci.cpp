// C++ code for calculating the nth fibonacci number using recursion and dynamic programming

#include<iostream>
using namespace std;

// recursion
int fibo(int n){

    // base case
    if(n==1 or n==0){
        return n;
    }

    // recursive case
    return fibo(n-1) + fibo(n-2);
}

// top down approach (recursion + memoization) - dynamic programming 
int topDown(int n, int* dp){

    // base case
    if(n==1 or n==0){
        // store before returning any value
        dp[n] = n;
        return dp[n];
    }

    // check before calculating
    if(dp[n] != -1){
        return dp[n];
    }

    // recursive case
    int ans = topDown(n-1, dp) + topDown(n-2, dp);
    // store before returning
    dp[n] = ans;
    return dp[n];
}

// bottom up approach (iterative) - dynamic programming
int bottomUp(int n){

    int *dp = new int[n+1];

    // initialize dp array
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    int ans = dp[n];

    // free up memory
    delete []dp;

    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int *dp = new int[n+1];
    for (int i = 0 ; i <= n ; i ++) {
        dp[i] = -1;
    }

    cout << topDown(n, dp) << endl;

    cout << bottomUp(n) << endl;

    cout << fibo(n) << endl;
}