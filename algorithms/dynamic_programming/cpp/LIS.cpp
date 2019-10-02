
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;


int LIS(int a[], int n){

// dp stores the lengths of LIS ending at index i
 int dp[10000]={1};

 for(int i=0; i<=n; i++){
     dp[i] = 1;
 }
 // initially all are 1 as the longest increasing subsequnce atleast contains the current element


 int best=-1;

// for all states previous to current state, find LIS if that state is smaller than current
 for(int i=1; i<n; i++){
 	for(int j=0; j<i; j++){
 		// if a[j]<a[i] means that the element can contribute in making LIS for a[i]
 		if(a[j]<=a[i]){
 			int ans = 1+dp[j];
 			dp[i]=max(ans,dp[i]);
 		}
 	}

    
 	// finding max LIS length from dp
 	best = max(best,dp[i]);
 }


return best;

}


int main(){
	
   int n;
   cin>>n;

   int a[n];

   for(int i=0; i<n; i++) cin>>a[i];

   	cout<<LIS(a,n)<<endl;


	return 0;
}