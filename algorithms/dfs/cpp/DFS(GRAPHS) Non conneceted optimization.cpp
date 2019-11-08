//DFS IMPLEMENTATION OF GRAPHS (Start at 0)
#include <bits/stdc++.h>
using namespace std;
#define X (1000000007);
vector<int> visited(1000001,0);

void print(vector<vector<int> > &v,int node){
  cout<<node<<" ";
  visited[node]=1;
  for(int i=0;i<v[node].size();i++){
    if(!visited[v[node][i]])
      print(v,v[node][i]);
  }

}

int main()
{   std::ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
   int n,e;
   cin>>n>>e;
   vector<vector<int> > v(n+1);
   for(int i=0;i<e;i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
   }
   for(int i=0;i<n;i++){
    if(!visited[i])
      print(v,i);
   }
    return 0;
}
