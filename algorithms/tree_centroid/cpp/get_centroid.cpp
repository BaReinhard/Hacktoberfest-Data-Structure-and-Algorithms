// by eopXD
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <climits>
#include <vector>
#define SZ(x) (int)((x).size())
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long LL;
const int N=100005; 	// max number of centroid
int n; 					// vertex(1~n)
int m; 					// number of edge
vector<int> edge[N]; 	// vector of edge
int size[N]; 			// collected vertex (in a rolling motion, see dfs())
int ans,balance; 		// centroid, balanced size
void init() {
	for ( int i=1; i<=n; i++ ) edge[i].clear();
	balance=INT_MAX;
}
void input () {
	scanf("%d%d",&n,&m);
	init();
	for ( int i=0; i<m; i++ ) {
		int x,y; scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}	
}
void go ( int x, int mom ) {	
	size[x]=1;
	int mx_sub=0;
	for ( int i=0; i<SZ(edge[x]); i++ ) {
		if ( edge[x][i]!=mom ) {
			go(edge[x][i],x);
			size[x]+=edge[x][i];
			mx_sub=max(mx_sub,size[edge[x][i]]);
		}
	}
	mx_sub=max(mx_sub,n-size[x]);
	if ( mx_sub<balance || (mx_sub==balance&&x<ans) ) 
		ans=x, balance=mx_sub;
	
}
PII get_centroid () {
	go(1,-1);
	return MP(ans,balance);
} 
int main ()
{
	input();
	PII ans=get_centroid();
	return 0;
}

