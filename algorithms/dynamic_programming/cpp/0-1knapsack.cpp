#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, int w, vector <int> val, vector <int> wt)
{
	vector<vector <int> > KS(n+1);
	for(int i=0;i<n+1;i++)
		for(int j=0;j<w+1;j++)
			KS[i].push_back(0);
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<w+1;j++)
		{
			if(i==0 || j==0)
				KS[i][j]=0;
			else if(wt[i-1]<=j)
			{
				KS[i][j]=max(val[i-1]+KS[i-1][j-wt[i-1]],KS[i-1][j]);
			}
			else
				KS[i][j]=KS[i-1][j];
		}
	}
	return KS[n][w];
}

int main()
{
	int t=0;
	cin>>t;
	
	while(t--)
	{
		int n,w;
		cin>>n>>w;
		
		vector <int> val (n);
		vector <int> wt (n);
		
		for(int i=0;i<n;i++)
			cin>>val[i];
		for(int i=0;i<n;i++)
			cin>>wt[i];

		int res=knapsack(n,w,val,wt);
		cout<<res<<endl;
	}
	
	return 0;
}
