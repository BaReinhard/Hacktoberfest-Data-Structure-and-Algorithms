#include <bits/stdc++.h>
using namespace std;
struct edge{
    int src,dest,wt;
};
bool cmp(edge e1,edge e2)
{
    return e1.wt < e2.wt;
}
int getParent(int v,int parent[]){
    if(parent[v] == v)
        return v;
    return getParent(parent[v],parent);
}
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */
    edge edges[E];
    for(int i=0;i<E;i++)
    {
        cin >> edges[i].src >> edges[i].dest >> edges[i].wt;
    }
    sort(edges,edges+E,cmp);
    edge output[V-1];
    int k=0;
    int count = 0;
    int parent[V];
    for(int i=0;i<V;i++)
    {
        parent[i] = i;
    }
    for(int i=0;i<E && count < V-1;i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int srcParent = getParent(src,parent);
        int destParent = getParent(dest,parent);
        if(srcParent != destParent)
        {
            parent[srcParent] = destParent;
            count++;
            output[k++] = edges[i];
        }
    }
    for(int i=0;i<count;i++)
    {
        if(output[i].src < output[i].dest)
            cout << output[i].src << " " << output[i].dest << " " << output[i].wt << endl;
        else
            cout << output[i].dest << " " << output[i].src << " " << output[i].wt << endl;
    }
  return 0;
}
