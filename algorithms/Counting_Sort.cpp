/*Maximum Value of a element in array should be 10^5 */
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int k[10000]={0};
	int *arr=new int [n+1];
	int B[n];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	for(int i=1;i<=n;i++)
		k[arr[i]]++;
	for(int i=1;i<10000;i++)
		k[i]=k[i]+k[i-1];
	for(int i=1;i<=n;i++)
	{
		B[k[arr[i]]]=arr[i];
		k[arr[i]]--;
	}
	for(int i=1;i<=n;i++)
		cout<<B[i]<<" ";
	delete [] arr;

	return 0;
}