#include<bits/stdc++.h>
using namespace std;
int col[100];
int G[100][100];
int nodes,edges;
bool bipartite(int src)
{
col[src]=1;
queue<int> q;
q.push(src);
while(!q.empty())
{
	int u=q.front();
	q.pop();
	for(int i=1;i<=nodes;i++)
	{
		if(G[u][i]==1 && col[i]==-1)
		{
			col[i]=1-col[u];
			q.push(i);
		}
		else
			if(G[u][i]==1 && col[i]==col[u])
				return false;
	}
}
return true;

}
int main()
{

	cin>>nodes>>edges;
	for(int i=0;i<100;i++)
	{
		col[i]=-1;
	for(int j=0;j<100;j++)
	{
		G[i][j]=0;
	}
}
	for(int i=0;i<edges;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u][v]=1;
		G[v][u]=1;

	}
	cout<<bipartite(1);

}
