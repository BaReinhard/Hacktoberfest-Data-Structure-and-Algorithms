#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> root;
vector<int> height;

int getRoot(int node) {

	if (node == root[node]) {
		return node;
	}
	return getRoot(root[node]);
}

void unify(int x, int y) {
	if (height[x] < height[y]) {
		root[x] = y;
	}
	else if (height[y] < height[x]) {
		root[y] = x;
	}
	else {
		root[x] = y;
		height[y]++;
	}
	return;
}

int main() {

	vector<pair <int, pair<int, int> > > V;

	cin >> N >> M;

	V.push_back(make_pair(0, make_pair(0,0)));
	for(int i = 1; i <= M; i++) {
		int cost, x, y;
		cin >> x >> y >> cost;
		V.push_back(make_pair(cost, make_pair(x,y)));
	}

	sort(V.begin(), V.end());

	int cost = 0;

	root.push_back(0);
	height.push_back(0);
	for (int i = 1; i <= N; i++) {
		root.push_back(i);
		height.push_back(1);
	}
	for (int i = 1; i <= M; i++) {
		int x = V[i].second.first;
		int y = V[i].second.second;
		int currentCost = V[i].first;

		if(getRoot(x) != getRoot(y)) {
			unify(getRoot(x), getRoot(y));
			cost += currentCost;
		}
	}

	cout<<cost<<"\n";

	return 0;
}
