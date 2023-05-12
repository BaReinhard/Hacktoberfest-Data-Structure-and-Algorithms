#include<bits/stdc++.h>
using namespace std;
int lis(int a[],int n)
{
	int dp[n];
	for(int i=0;i<n;i++)
		dp[i]=1;
	int x=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(a[i]>=a[j])
				dp[i]=dp[j]+1;
	for(int i=0;i<n;i++)
		x=max(x,dp[i]);
	return x;
}
int main()
{
	int n=5;
	int a[5]={1,3,2,4,6};
	cout<<lis(a,n)<<endl;
}
