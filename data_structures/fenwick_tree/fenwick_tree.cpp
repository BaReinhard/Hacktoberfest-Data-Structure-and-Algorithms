#include<iostream>
using namespace std;
int bit[100];
int n;
void update(int x, int u)
{
	while(x<=n)
	{
		bit[x] += u;
		x += (x&-x);
	}
}
int getsum(int x)
{
	int sum = 0 ;
	while(x>0)
	{
		sum += bit[x];
		x -= (x&-x);
	}
	return sum;
}
int main()
{
	cin>>n;
	int a[n+1];
	for(int i=0;i<=n;i++)
		bit[i] = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		update(i, a[i]);
	}
	//Number of queries
	int q;
	cin>>q;
	while(q--)
	{
		int t,l,r;
		cin>>t>>l>>r;
		if(t==0)
			update(l, r);
		if(t==1)
			cout<<getsum(r)-getsum(l-1)<<endl;
	}
}

