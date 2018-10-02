// a program that finds the lowest common ancestor of a given tree

#include <bits/stdc++.h>
using namespace std;
const int N = 200004;
int all;
vector<vector<pair<int,pair<int,int> > > > g;
// up is an array that contains the 2^nth parent for a node
// dpth is an array that contains the level of a node (distance from root)
int up[N][17],dpth[N];

void fill(int node=1,int parent=0){
	// function that fills the up array
    dpth[node]= dpth[parent]+1;
    up[node][0]=parent;
    for (int i=1 ; i<17 ; i++){
    	// the 2^ith parent of this node is the 2^(i-1)th parent of parents node
        up[node][i]= up[up[node][i-1]][i-1];
    }
    for (int i=0 ; i<g[node].size() ; i++){
    	// fill all children 
        if (g[node][i].first != parent) fill(g[node][i].first,node);
    }
}
int kth (int node, int dist){
	// function gives kth parent of a node by slicing the number to powers of two
    for (int i=16 ; i>=0 ; i--){
        if (dist>>i &1){ // if dist is lower or equal to i
            node=up[node][i];
        }
    }
    return node;
}
int lca (int x, int y){
	// function that makes two nodes same level then gives lca
    if (dpth[x] > dpth[y]) swap(x,y); // y lowest, larger depth
    int dist = abs(dpth[x] - dpth[y]);
    y = kth(y,dist); // same level
    if (x==y) return x;
    for (int i=16 ; i>=0 ; i--){
    	// keep trying until there is difference between 2^ith parent
        if (up[x][i] != up[y][i]) { x=up[x][i],y=up[y][i]; }
    }
    return up[x][0];
}

int main (){
    freopen("input.txt","r",stdin);
	int t ; scanf("%d",&t);
	while (t--){
		int n; scanf("%d",&n);
		g.resize(n+1);
		for (int i=0 ; i<n-1 ; i++){
			int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
			g[a].push_back({b,{c,d}});
			g[b].push_back({a,{d,c}});
            all+=c+d;
		}
		fill();
		int t; scanf("%d",&t);
		for (int i=0 ; i<t ; i++){
			int x,y; scanf("%d%d",&x,&y);
			int prnt = lca(x,y);
            int res = all -
		}
	}
}
