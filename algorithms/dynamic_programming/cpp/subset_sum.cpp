#include<bits/stdc++.h>
using namespace std;
int arr[1000];
int sum=0;
int cache[100][100];
int m_diff(int idx,int sub_sum)
{
	if(cache[idx][sub_sum])
		return cache[idx][sub_sum];

	if(idx==0)
	{
		cache[0][sub_sum]=abs((sum-sub_sum)-sub_sum);
		return cache[0][sub_sum];
	}
	cache[idx][sub_sum]=min(m_diff(idx-1,sub_sum-arr[idx]),m_diff(idx-1,sub_sum));
	return cache[idx][sub_sum];
}
int main()
{
	memset(cache,0,sizeof cache);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		cout<<m_diff(n,sum)<<endl;
}