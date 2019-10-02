
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

map<ll,ll> memo;

// This code is based on a blog entry in Codeforces 
// https://codeforces.com/blog/entry/14516

ll fib(ll n){


     if(memo.count(n))
     	return memo[n];

     ll k = n/2;

     // these formulae can be found in the above blog entry
     
     if(n%2==0){   // n= 2k i.e even
     	return memo[n] = (fib(k)*fib(k) + fib(k-1)*fib(k-1))%MOD;
     }

     else{    // n = 2k+1 i.e odd
     	return memo[n] = (fib(k)*fib(k+1) + fib(k-1)*fib(k))%MOD;
     }
}

int main(){

	memo[0]=1;
	memo[1]=1;

   ll n;
   cin>>n;

   cout<<((n==0)? 0 :fib(n-1))<<endl;


	return 0;
}