/* 1. shortest path from source to vertices
   2. can be used for negetive weights
   3.can be used to detect neg cycle.
   */
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define INF (1<<20);
pair<int ,pii> G[1000];
int dis[1000];

int main()
{
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[i]=mp(u,mp(v,w));
	//	v[v].push_back(mp(u,w)); for undirected;
	}
	for(int i=1;i<=nodes;i++)
		dis[i]=INF;
	dis[1]=0;
	for(int i=0;i<nodes-1;i++)
	{
	for(int j=0;j<edges;j++)
	{
		int u,v,w;
		u=G[j].first;
		v=G[j].second.first;
		w=G[j].second.second;
		if(dis[v]>dis[u]+w)
		{
			dis[v]=dis[u]+w;
		}
	}
	}
	bool negc=false;
	for(int j=0;j<edges;j++)
	{
		int u,v,w;
		u=G[j].first;
		v=G[j].second.first;
		w=G[j].second.second;
		if(dis[v]>dis[u]+w)
		{
			negc=true;
			break;
		}
	}
	if(negc)
	cout<<"negetive cycle";
	else
	{
		for(int i=1;i<=nodes;i++)
		{
			cout<<"1"<<" - "<<i<<"= "<<dis[i]<<endl;
		}
	}


}

