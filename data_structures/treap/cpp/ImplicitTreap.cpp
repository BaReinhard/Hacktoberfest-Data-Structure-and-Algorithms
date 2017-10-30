// Code for problem HORRIBLE in Spoj, example usage of Implicit Treap
#include<bits/stdc++.h>
using namespace std;

#define sd(a) scanf("%d",&a)
#define ss(a) scanf("%s",&a)
#define sl(a) scanf("%lld",&a)
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define rep(i)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define N 200010
#define INF 1000000000

struct node
{
	int prior,size;
	ll val;//value stored in the array
	ll sum;//whatever info you want to maintain in segtree for each node
	ll lazy;//whatever lazy update you want to do
	int l,r;
}t[N];
int node_cnt;
int sz(int n)
{
	if(n==-1)
		return 0;
	return t[n].size;
}
void upd_sz(int n)
{
	if(n==-1)	return;
	t[n].size=sz(t[n].l)+1+sz(t[n].r);
}
void push(int n)
{
	if(n==-1)		return;
	if(!t[n].lazy)	return;
	
	t[n].val+=t[n].lazy;//operation of lazy
	t[n].sum+=t[n].lazy*t[n].size;
	
	if(t[n].l >= 0)
		t[t[n].l].lazy+=t[n].lazy;//propagate lazy
	if(t[n].r >= 0)
		t[t[n].r].lazy+=t[n].lazy;//propagate lazy
	t[n].lazy=0;
}
inline ll getsum(int n)
{
	return n==-1?0:t[n].sum;
}
void refresh(int n)
{//operation of segtree
	if(n==-1)	return;
	
	push(t[n].l);push(t[n].r);//imp:propagate lazy before combining t->l,t->r;
	t[n].sum = t[n].val + getsum(t[n].l) + getsum(t[n].r);
}
pair<int,int> split(int n,int pos,int add=0)
{
	pair<int,int> ret=MP(-1,-1);
	if(n==-1)
		return ret;
	push(n);
	int curr_pos = add + sz(t[n].l);
	if(curr_pos<=pos)//element at pos goes to left subtree(l)
	{
		pair<int,int> p=split(t[n].r,pos,curr_pos+1);
		t[n].r = p.F;
		ret.S = p.S;
		ret.F = n;
	}
	else 
	{
		pair<int,int> p=split(t[n].l,pos,add);
		ret.F = p.F;
		t[n].l = p.S;
		ret.S = n;
	}
	upd_sz(ret.F);refresh(ret.F);
	upd_sz(ret.S);refresh(ret.S);
	return ret;
}
int merge(int l,int r)
{
	int ret;
	push(l);push(r);
	if(l==-1)
		ret = r;
	else if(r==-1)
		ret = l;
	else if(t[l].prior > t[r].prior)
	{
		t[l].r = merge(t[l].r,r);
		ret=l;
	}
	else
	{
		t[r].l = merge(l,t[r].l);
		ret=r;
	}
	upd_sz(ret);
	refresh(ret);
	return ret;
}
int init(int val){
	int ret = ++node_cnt;
	t[ret].prior=rand();
	t[ret].size=1;
	t[ret].val=t[ret].sum=val;
	t[ret].lazy=0;
	t[ret].l=t[ret].r=-1;
	return ret;
}

// range query
ll query(int &n,int l,int r){//[l,r]
	pair<int,int> p = split(n,l-1);
	pair<int,int> p1= split(p.S,r-l);//note: r-l!!
	refresh(p1.F);
	ll sum = (p1.F==-1?-INF:t[p1.F].sum);
	int n1 = merge(p.F,p1.F);
	n = merge(n1,p1.S);
	return sum;
}

//range update
void update(int &n,int l, int r,ll val){
	pair<int,int> p = split(n,l-1);
	pair<int,int> p1 = split(p.S,r-l);
	if(p1.F>=0)
	{
		t[p1.F].lazy += val;
	}
	int n1 = merge(p.F,p1.F);
	n = merge(n1,p1.S);
}

void Insert(int &n,int pos,ll val){
	pair<int,int> p = split(n,pos-1);
	int n1=merge(p.F,init(val));
	n = merge(n1,p.S);
}

int a[N];
int main()
{
	int t;
	sd(t);
	while(t--)
	{
		int n,m,i;
		sd(n);sd(m);
		node_cnt=-1;
		int root=-1;
		for(i=0;i<n;++i)
			root = merge(root,init(0));
		while(m--)
		{
			int ch;
			int x,y;
			sd(ch);sd(x);sd(y);
			--x;--y;
			if(ch==0)
			{
				int z;
				sd(z);
				update(root, x, y, z);
			}
			else
				printf("%lld\n",query(root, x, y));
		}
	}
	
}