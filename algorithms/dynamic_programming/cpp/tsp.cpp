//This dynamic programming solves the TSP (traveling postman problem) in O(n²2^n). The points are modeled in a 2D plane
#include <bits/stdc++.h>

using namespace std;

const int N = 11, inf = (int) 1e9 + 7;
int n, m, kn, km, b;
int x[N], y[N];
int dp[N][1 << N], used[N][1 << N], test;

int dis(int x1, int y1, int x2, int y2){//The distance between two points is the manhattan distance
	return abs(x1 - x2) + abs(y1 - y2);
}

int solve(int i, int s){//*i* is the current point and *s* the mask of visited points
	int &ans = dp[i][s];
	
	if(used[i][s] == test){
		return ans;
	}
	
	used[i][s] = test;
	ans = inf;
	bool find = false;
	
	for(int k = 0 ; k < b ; k++){
		int chk = 1 << k;
		
		if((s & chk) == 0){//If point *k* is not visited then go to *k* from *i*
			find = true;
			ans = min(ans, solve(k, s | chk) + dis(x[i], y[i], x[k], y[k]));
		}	
	}
	
	if(!find){
		ans = dis(kn, km, x[i], y[i]);
	}
	
	return ans;
}

int main (){
	int t;

	test++;
	
	scanf("%d%d", &kn, &km);//(Kn, Km) is you current point.
	scanf("%d", &b);//b is the number of points that we need to take.
	
	for(int i = 0 ; i < b ; i++){//read the points.
		scanf("%d%d", &x[i], &y[i]);
	}
	
	int ans = inf;
	
	for(int i = 0 ; i < b ; i++){//try starting from each of the points.
		ans = min(ans, solve(i, 1 << i) + dis(kn, km, x[i], y[i]));
	}
	
	printf("The shortest path has length %d\n", ans);
	

	return 0;
}