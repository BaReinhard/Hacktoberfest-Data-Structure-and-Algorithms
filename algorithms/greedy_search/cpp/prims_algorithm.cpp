#include <bits/stdc++.h>
using namespace std;

int minkey(int key[], bool mstset[],int n)
{
	int min_index;
	int Min = INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(mstset[i]==false and key[i]<Min)
		{	
			Min= key[i];
			min_index = i;
		}
	}
	return min_index;
}
int main()
{
	int n;
	cout<<"enter the number of vertices in the graph\n";
	cin>>n;
	int cost[n][n];
	memset(cost,0,sizeof(cost));
	int m;
	cout<<"enter the number of edges in the graph\n";
	cin>>m;
	vector<pair<int,int> > edgelist(m);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cout<<"enter the "<<i+1<<" edge and the weight\n";
		cin>>a>>b>>c;
		edgelist[i] = make_pair(a,b);
		cost[a][b] =c;
		cost[b][a] =c;
	}
	bool mstset[n];
	pair<int,int> edge[n];
	int key[n];
	for(int i=0;i<n;i++)
	{
		key[i]= INT_MAX;
		mstset[i] = false;
	}
	key[0] =0;
	for(int i=0;i<n-1;i++)
	{
		int u = minkey(key,mstset,n);
		mstset[u] = true;
		for(int v=0;v<n;v++)
		{
			if(cost[u][v] and mstset[v]==false and cost[u][v] < key[v])
			{
				key[v] = cost[u][v];
				edge[v] = make_pair(u,v);
			}
		}
	}
	cout<<"the edges of the  minimum spanning tree are\n";
	for(int i=1;i<n;i++)
		cout<<edge[i].first<<"--"<<edge[i].second<<endl;
	for(int i=0;i<m;)
	{
		int j;
		for(j=0;j<n;j++)
		{
			if((edgelist[i].first== edge[j].first and edgelist[i].second == edge[j].second) or (edgelist[i].first== edge[j].second and edgelist[i].second == edge[j].first))
			{
				edgelist.erase(edgelist.begin()+i);
				break;
			}
		}
		if(j==n)
			++i;
	}
	 cout<<"the edges not in minimum spanning tree are \n";
	cout<<"edge"<<"  "<<endl;
	for(int i=0;i<edgelist.size();i++)
		cout<<edgelist[i].first<<"--"<<edgelist[i].second<<"\n";
	return 0;
}
