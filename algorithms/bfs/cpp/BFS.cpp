
		//Bfs for undirected and unweighted graph

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
using namespace std ;
map<char,vector<char>> edges;

void BFS(char root)
{
	cout << "\nBFS : " ;
	queue <char> visitRank ;
	map <char,bool> visited ;

	char currNode = root ;
	visitRank.push(currNode);
	visited[currNode]=true;
	while(!visitRank.empty())
	{
		currNode = visitRank.front();
		for(auto c : edges[currNode])
			if(!visited[c])
				visitRank.push(c),visited[c]=true;
		cout << currNode << " ";
		visitRank.pop();
	}
}


void DFS(char root)
{
	cout << "\nDFS : " ;
	stack <char> visitRank;
	map <char,bool> visited ;
	char currNode = root ;
	visitRank.push(currNode);
	visited[currNode]=true;
	while(!visitRank.empty())
	{
		cout << currNode << " ";
		currNode = visitRank.top();
		for(auto c : edges[currNode])
			if(!visited[c])
				visitRank.push(c),visited[c]=true,currNode=c;
		visitRank.pop();
	}
}

int main()
{
	int totalNodes,totalEdges ;

	cout << "Enter Total Nodes : " ;
	cin >> totalNodes ;
	cout << "Enter total number of Edges : ";
	cin >> totalEdges ;


	char u,v ;

	rep(i,0,totalEdges)
	{
		cin >> u >> v ;
		edges[u].pb(v);
		edges[v].pb(u);
	}
	char root ;
	cout << "Enter Root : " ;
	cin >> root ;
	while(edges[root].size()==0)
	{
		cout << "Not Valid Root Node, " << "Enter Again : " ;
		cin >> root ;
	}
	BFS(root);
	DFS(root);
}

/*
A B
A C
B D
B E
D E
E F
C H
C G
G H
*/

