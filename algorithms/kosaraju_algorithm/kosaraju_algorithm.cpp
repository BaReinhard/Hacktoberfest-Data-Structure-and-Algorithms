#include<bits/stdc++.h>
using namespace std;
 #define MAX 10001
int kosaraju(vector<int> adj[100001],int ,int );
void dfsfill(vector<int> adj[],int V,int root,int vis[],stack<int> &s){
    vis[root]=1;
    for(int i=0;i<adj[root].size();i++){
        if(vis[adj[root][i]]==0) dfsfill(adj,V,adj[root][i],vis,s);
    }
    s.push(root);
}
void dfs(vector<int> adj[],int V,int vis[],int root){
    vis[root]=1;
    for(int i=0;i<adj[root].size();i++){
        if(vis[adj[root][i]]==0) dfs(adj,V,vis,adj[root][i]);
    }
}
void getTranspose(vector<int> adj[],vector<int> res[],int V){
    for(int i=1;i<=V;i++){
        for(int j=0;j<adj[i].size();j++){
            res[adj[i][j]].push_back(i);
        }
    }
}
int kosaraju(vector<int> adj[100001], int N, int M)
{
    int count=0;
    stack<int> s;
    int vis[N+1]={0};
    for(int i=1;i<=N;i++){
        if(vis[i]==0) dfsfill(adj,N,i,vis,s);
    }
    vector<int> gt[100001];
    getTranspose(adj,gt,N);
    for(int i=1;i<=N;i++) vis[i]=0;

    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(vis[top]==0){
            dfs(gt,N,vis,top);
            count++;
        }
    }
    return count;
}

int main()
{
   int t;
   cin>>t;
  while(t--)
   {   vector<int> v[100001];
        int a,b ;
   	cin>>a>>b;
       for(int i=0;i<b;i++)
           {  int m,n;
               cin>>m>>n;
               v[m].push_back(n);
           }


         int ans=kosaraju(v,a,b);
         cout<<ans<<endl;
         for(int i=0;i<=a+1;i++)
        {    v[i].clear();
         }

   }


}

