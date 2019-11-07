#include <bits/stdc++.h>

using namespace std;

/*
*	Algorithm that calculates the distance between all vertices
*	of a graph.
*
* 	Further reading at:
*	https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
*/

void floydWarshall( vector< vector < int > > d ){
	const int n = v.size();
	const int INF = 1e8;
	for(int k = 0;k < n;++k){
		for(int i = 0;i < n;++i){
			for(int j = 0;j < n;++j){
				if(d[i][k] < INF && d[k][j] < INF){
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
} 