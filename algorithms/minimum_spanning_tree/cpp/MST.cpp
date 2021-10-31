#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int parent[1000];
int size[1000];

//// union find
void init()
{
	for(int i=0;i<1000;i++)
	{
		parent[i]=i;
	}

}
int root(int i)
{
	while(parent[i]!=i)
	{
		parent[i]=parent[parent[i]];
		i=parent[i];
	}
	return i;
}
void unio(int a,int b)
{
	int root_a=root(a);
	int root_b=root(b);
	parent[root_a]=parent[root_b];
}

////// krushkal()
#define ll long long
#define mp make_pair
vector<pair <int, pair<int,int> > > v;
ll nodes,edges;

ll kruskal(){

 int x,y;
 ll cost=0,mincost=0;
 // step 2. loop through sorted array until all nodes are in same set
 for(ll i=0;i<edges;i++)
 {
 	x=v[i].second.first;
 	y=v[i].second.second;
 	cost=v[i].first;
 	if(root(x)!=root(y))
 	{
 		mincost+=cost;
 		unio(x,y);
 	}
 }
 return mincost;
 }


int main()
{
init();
cin>>nodes>>edges;
for(int i=0;i<edges;++i)
{
	int a,b;
	int w;
	cin>>a>>b>>w;
	v.push_back(make_pair(w, make_pair(a, b)));
}
// 1. step is to sort all the edges by its weights
sort(v.begin(),v.end());
cout<<"ans ="<<kruskal();
}
