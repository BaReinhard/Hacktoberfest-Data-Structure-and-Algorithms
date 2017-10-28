#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> pii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pii> vpii;
typedef long long int ll;

#define rep(i,a,b) for(i=a;i<b;i++)
#define repv(i,a,b) for(i=b-1;i>=a;i--)
#define PB push_back
#define MP make_pair
#define fi first
#define se second

const int inf=1e9,N=2e6+10,dollar=257;
map<int,int> to[N];
int s[N];
int len[N]={inf},fps[N],link[N],k;
int node,pos,sz=1,n=0;
int totlen;
int make_node(int _pos,int _len,int _par)
{
  fps[sz]=_pos;
  len[sz]=_len;
  return sz++;
}
void go_edge()
{
  while(pos>len[to[node][s[n-pos]]])
    {
      node=to[node][s[n-pos]];
      pos-=len[node];
    }
}
void add_letter(int c)
{
  s[n++]=c;
  pos++;
  int last=0;
  while(pos>0)
    {
      go_edge();
      int edge=s[n-pos];
      int &v=to[node][edge];
      int t=s[fps[v]+pos-1];
      if(v==0)
	{
	  v=make_node(n-pos,inf,node);
	  if(len[v]==inf)
	    len[v]=totlen-fps[v];
	  link[last]=node;
	  last=0;
	}
      else if(t==c)
	{
	  link[last]=node;
	  return;
	}
      else
	{
	  int u=make_node(fps[v],pos-1,node);
	  to[u][c]=make_node(n-1,inf,u);
	  len[to[u][c]]=totlen-fps[to[u][c]];
	  to[u][t]=v;
	  fps[v]+=pos-1;
	  len[v]-=pos-1;
	  v=u;
	  link[last]=u;
	  last=u;
	}
      if(node==0)
	pos--;
      else
	node=link[node];
    }
}
int main()
{
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++)
    add_letter(s[i]);
  
  return 0;
}
