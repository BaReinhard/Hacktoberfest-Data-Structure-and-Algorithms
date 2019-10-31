#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> g[],int u,int v){
       g[u].push_back(v);
    //   g[v].push_back(u);
}

void print(vector<int> g[],int V){
     for(int i=0;i<V;++i){
        printf("\nAdjacency list of %d: ",i);
        for(int j=0;j<g[i].size();j++)
            printf(" -> %d",g[i][j]);
     }
}

void dfs(vector<int> g[],int V,int root){
     stack<int> s;
     int i,vis[V]={0};
     s.push(root);
     vis[root]=1;
     printf("\n\n %d",root);
     while(!s.empty()){
            int next=s.top();
            for(i=0;i<g[next].size();i++){
                if(vis[g[next][i]]==0){
                    s.push(g[next][i]);
                    vis[g[next][i]]=1;
                    printf(" %d ",g[next][i]);
                    break;
                }
            }
            if(i==g[next].size()){
                s.pop();
            }
     }
}

int main(){
       int v,e,u,w,root;
       scanf("%d%d",&v,&e);
       vector<int> g[v];
       for(int i=1;i<=e;i++){
        scanf("%d%d",&u,&w);
        addEdge(g,u,w);
       }
       dfs(g,v,2);
}
