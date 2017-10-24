#include <bits/stdc++.h>
using namespace std;
typedef struct mat
{
	int r;
	int c;
	int v;
}mat;
mat a[100];
mat ans[100];
int main()
{
	int n;
	cin>>n;
	int row=0,column=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i].r>>a[i].c>>a[i].v;
		row=max(a[i].r,row);
		column=max(column,a[i].c);
	}
	int sp[column+1];
	int freq[column+1];
	memset(freq,0,sizeof(freq));
	memset(sp,0,sizeof(sp));
	for(int i=0;i<n;i++)
	{
		freq[a[i].c]++;
	}
	sp[0]=0;
	for(int i=1;i<=column;i++)
	{
		sp[i]=sp[i-1]+freq[i-1];
		
	}
	for(int i=0;i<n;i++)
	{
		
		
			ans[sp[a[i].c]].r=a[i].c;
			ans[sp[a[i].c]].c=a[i].r;
			ans[sp[a[i].c]].v=a[i].v;
			sp[a[i].c]++;
			freq[a[i].c]--;
		
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i].r<<" "<<ans[i].c<<" "<<ans[i].v<<endl; 
	}



}