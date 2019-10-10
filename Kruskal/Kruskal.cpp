#include <bits/stdc++.h>
using namespace std;



int findparent(const vector<int> &parent,int node){
    while(node!=parent[node]){
        node=parent[node];
    }
    return node;
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
  vector< pair<int,pair<int,int> > > edges(E),output;
  for(int i=0;i<E;i++)cin>>edges[i].second.first>>edges[i].second.second>>edges[i].first;
  sort(edges.begin(),edges.end());
  vector<int> parent(V);
  for(int i=0;i<V;i++)parent[i]=i;
    
 for(int i=0;i<E&&output.size()!=V-1;i++){
     int u=edges[i].second.first;
     int v=edges[i].second.second;
     int pu=findparent(parent,u);
     int pv=findparent(parent,v);
     if(pu!=pv){
         parent[pv]=pu;
         output.push_back(edges[i]);
     }
 }
  for(int i=0;i<V-1;i++){
      int x=min(output[i].second.first,output[i].second.second);
      int y=max(output[i].second.first,output[i].second.second);
      cout<<x<<" "<<y<<" "<<output[i].first<<endl;
  }

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */

  return 0;
}
