/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define MAXSIZE 100005
#define mod 1000000007
#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = a; i > b; i--)
#define INF INT_MAX
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a, b, sizeof(a))

//debugging statements
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

// I've used the example of sum of a range to depict the lazy propogation.
const LL N = 1e5+10;

LL tree[4*N], lazy[4*N];

LL query(LL low, LL high, LL pos, LL l, LL r) { 

  // if current node is not updated
  if (lazy[pos]) { 
    tree[pos] += lazy[pos]*(high-low+1);
    if(low != high) {
      lazy[2*pos] += lazy[pos];
      lazy[2*pos+1] += lazy[pos];
    }
    lazy[pos] = 0;
  }

  //if no overlap
  if( (l > high) || (r < low) || low > high)
    return 0;
  //compete overlap;
  else if(l <= low && r >= high)
    return tree[pos];
  //partial overlap
  LL mid = (low + high) >> 1;
  return (query(low, mid, 2*pos, l, r) + query(mid + 1, high, 2*pos + 1, l, r));
}

void range_update(LL low, LL high, LL pos, LL l, LL r, LL val) { 
  //no overlap
  
  if(lazy[pos]) {
    tree[pos] += (high-low+1)*lazy[pos];
    if(low != high) { 
      lazy[2*pos] += lazy[pos];
      lazy[2*pos+1] += lazy[pos];
    }
    lazy[pos] = 0;
  }


  if( (l > high) || (r < low) || (low > high)) 
    return; 
  //complete overlap 
  else if(l <= low && r >= high) {
    tree[pos] += (high-low+1)*val;
    if(low != high) { 
      	lazy[2*pos] += val;
      	lazy[2*pos+1] += val;
      }
    return; 
  }
  //partial overlap
  LL mid = (low + high) >> 1;
  range_update(low, mid, 2*pos, l, r, val);
  range_update(mid + 1, high, 2*pos + 1, l, r, val);
  tree[pos] = tree[2*pos] + tree[2*pos+1];
  return;
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  LL T;
  cin >> T;
  while(T--) { 
    SET(lazy, 0);
    SET(tree, 0);
    LL n, c, opt, a, b, d;
    cin >> n >> c;
    while(c--) {
      cin >> opt;
      if(opt) {
        cin >> a >> b;
        cout << query(1, n, 1, a, b) << endl;
      }
      else {
        cin >> a >> b >> d;
        range_update(1, n, 1, a, b, d);
      }
    }
  }
  return 0;
}
