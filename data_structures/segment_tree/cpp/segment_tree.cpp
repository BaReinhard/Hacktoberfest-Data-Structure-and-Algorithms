#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;

const ll MAXN = 10e5 * 2 + 5;

pair<ll, ll> st[MAXN];
vector<ll> vet;
ll n, lazy[MAXN];

ll left(ll p) { return (p << 1); }
ll right(ll p) { return (p << 1)+1; }

void build(ll p, ll l, ll r)
{
	if(l == r){
		st[p].F = l;
		st[p].S = vet[l-1];
	}
	else
	{
		ll p1 = left(p);
		ll p2 = right(p);
		ll mid = (l+r)/2;
		
		build(p1, l, mid);
		build(p2, mid+1, r);
		
		if(st[p1].S > st[p2].S){
			st[p].F = st[p1].F;
			st[p].S = st[p1].S;
		}
		else if(st[p2].S > st[p1].S){
			st[p].F = st[p2].F;
			st[p].S = st[p2].S;
		}
		else{
			st[p].F = min(st[p1].F, st[p2].F);
			st[p].S = st[p1].S;
		}
	}
}

void update(ll p, ll l, ll r, ll a, ll b, ll v)
{
	if(lazy[p] != 0){
		st[p].S += lazy[p];
		
		if(l != r){
			lazy[left(p)] += lazy[p]; 
			lazy[right(p)] += lazy[p];
		}
		
		lazy[p] = 0;
	}
	
	if(r < a || l > b)
		return;
		
	if(a <= l && b >= r){
		st[p].S += v;
		
		if(l != r){
			lazy[left(p)] += v; 
			lazy[right(p)] += v;
		}
		
		return;
	}
	
	ll p1 = left(p);
	ll p2 = right(p);
	ll mid = (l+r)/2;
	
	update(p1, l, mid, a, b, v);
	update(p2, mid+1, r, a, b, v);
	
	if(st[p1].S > st[p2].S){
		st[p].F = st[p1].F;
		st[p].S = st[p1].S;
	}
	else if(st[p2].S > st[p1].S){
		st[p].F = st[p2].F;
		st[p].S = st[p2].S;
	}
	else{
		st[p].F = min(st[p1].F, st[p2].F);
		st[p].S = st[p1].S;
	}
}

ii query(ll p, ll l, ll r, ll a, ll b)
{
	if(lazy[p] != 0)
	{
		st[p].S += lazy[p];
		
		if(l != r){
			lazy[left(p)] += lazy[p];
			lazy[right(p)] += lazy[p];
		}
		
		lazy[p] = 0;
	}
	
	if(r < a || l > b)
		return {-1, -1};
		
	if(a <= l && b >= r)
		return st[p];
		
	ll p1 = left(p);
	ll p2 = right(p);
	ll mid = (l+r)/2;
	
	ii res1 = query(p1, l, mid, a, b);
	ii res2 = query(p2, mid+1, r, a, b);
	ii res;
	
	if(res1.S > res2.S){
		res.F = res1.F;
		res.S = res1.S;
	}
	else if(res2.S > res1.S){
		res.F = res2.F;
		res.S = res2.S;
	}
	else{
		res.F = min(res1.F, res2.F);
		res.S = res1.S;
	}
	
	return res;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	char c;
	ll q;
	
	//n = length of array
	//q = number of querys
	while(cin >> n >> q)
	{
		vet.clear();
		memset(lazy, 0, sizeof lazy);
		
		ll num;
		//Initial values for the array
		for(ll i = 0; i < n; i++)
		{
			cin >> num;
			vet.push_back(num);
		}
		
		//build the segment tree
		build(1, 1, n);
		
		//x and y are positions of the array
		//v is the new value to add in the interval (x, y)
		ll x, y, v;
		while(q--)
		{
			cin >> c;
			
			if(c == "ADD"){
				cin >> x >> y >> v;
				update(1, 1, n, x, y, v);
			}
			else if(c == "QUERY"){
				cin >> x >> y;
				ii res = query(1, 1, n, x, y);
				
				cout << res.F << endl;
			}
		}
	}
}

