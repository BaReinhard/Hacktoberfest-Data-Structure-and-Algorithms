//This algorithm compute (a^x mod m) in O(log x)
#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

ll fast_expo(ll a, ll x, ll m){
	ll b = 1LL;
	ll d = x;

	while(x){
		if(x & 1){
			b = (b * d) % m;
		}

		d = (d * d) % m;
		x >>= 1LL;
	}

	return b;
}

int main(){
	ll a, x, m;

	cin >> a >> x >> m;

	cout << fast_expo(a, x, m) << '\n';

	return 0;
}