#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int data[MAXN];
int fen_tree[MAXN];

void Update(int a, int agregado) {
	for (++a; a < MAXN; a += a & -a)
		fen_tree[a] += agregado;
}

int SumUp(int a) {
	int sum = 0;
	for (++a; a; a -= a & -a)
		sum += fen_tree[a];
	return sum;
}

int IntervalSum(int a, int b) {
	return SumUp(b) - SumUp(a - 1);
}

int main() {  
	int n, q;
	cin >> n >> q;
	
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
		Update(i, data[i]);
	}
	
	for (int i = 0; i < q; ++i) {
		char type; // U: Update, Q: Query
		int a, b;
		cin >> type >> a >> b;
		if (type == 'U') {
			Update(a, b - data[a]);
			data[a] = b;
		} else {
			cout << IntervalSum(a, b) << "\n";
		}
	}
	
	return 0;
}
