#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(vector <int> adj[],int u,int v)
{
    adj[u].push_back(v);
}
bool dfsRec(int s,vector <int> adj[],bool vis[],bool recSt[])
{
    recSt[s]=true;
    vis[s]=true;
    for(int j=0;j<adj[s].size();j++)
    {
        if(vis[adj[s][j]]==false)
        {
            if(dfsRec(adj[s][j],adj,vis,recSt))
                return true;

        }
        else if(recSt[adj[s][j]]==true)
            return true;
    }
    recSt[s]=false;
    return false;
}
bool dfs(vector <int> adj[],int V)
{
    bool vis[V+1];
    bool recSt[V+1];
    for(int i=0;i<=V;i++)
    {
        vis[i]=false;
        recSt[i]=false;
    }
    for(int i=0;i<V;i++)
    {
        if(vis[i]==false)
        {
           if(dfsRec(i,adj,vis,recSt)==true)
                return true;
        }
    }
    return false;
}
int main()
{
    int V=6;
    vector <int> adj[V];
    addedge(adj,0,1);
     addedge(adj,2,1);
     addedge(adj,2,3);
     addedge(adj,3,4);
     addedge(adj,4,5);
     addedge(adj,5,3);
     if(dfs(adj,V))
        cout<<"Contains Cycle";
     else
        cout<<"No cycle";
}
