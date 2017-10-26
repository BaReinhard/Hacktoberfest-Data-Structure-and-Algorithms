//
// Created by ioana on 13.04.2017.
//
#include<iostream>
#include <vector>
#include <stack>

using namespace std;

int timer = 1, root;
vector<int> idx(10), lowlink(10), visited(10);
vector<int> G[10];
stack<int> stack1;

void tarjan (int v){
	idx[v] = timer;
	lowlink[v] = timer;
	timer++;

	vector<int> copii;

	for(int j = 0; j < G[v].size(); j++){
		if(!idx[ G[v][j] ]){
			copii.push_back(G[v][j]);
			tarjan(G[v][j]);
			lowlink[v] = min(lowlink[v], lowlink[ G[v][j] ]);
		}
		else{
			//if (visited[G[v][j]])
				lowlink[v] = min(lowlink[v], idx[ G[v][j] ]);
		}
	}

	if(v == root){
		if (copii.size() >= 2){
			cout<<v<<endl;
		}
	}
	else{
		int ok = 0;
		for(int j = 0; j < G[v].size(); j++){
			if(lowlink[G[v][j]] >= idx[v]){
				ok = 1;
			}
		}
		if(ok){
			cout<<v<<endl;
		}
	}
}

int main(){

	int N, x, y, M;
	cin >> N >> M;

	for(int i = 0; i < M; i++){
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	for (int i = 1; i <= N; i++){
		root = i;
		if(!idx[i])
			tarjan(i);
	}

	cout << "idx: ";
	for(int i = 1;i < 9; i++)  {
		cout << idx[i] << ' ';
	}
	cout <<endl;

	cout << "low: ";
	for(int i = 1;i < 9; i++)  {
		cout << lowlink[i] << ' ';
	}
	cout <<endl;
}
