#include <bits/stdc++.h>

using namespace std;

class UnionFind{
	vector<int> parent;
	vector<int> size;
	int components;
	
	// Finds the root of p, which is the identifier of its component	
	int root(int p){
		while(p != parent[p]){
			parent[p] = parent[parent[p]];
			p = parent[p];
		}
		return p;
	}

	// Creates the Union-Find data structure
	// N = number of components	 
	public:
	UnionFind(int N){
		components = N;
		for(int i=0; i<N; i++){
			parent.push_back(i);
			size.push_back(1);
		}
	}

	// Merges the component containing p and the component containing q	
	void unionElem(int p, int q){
		int rootP = root(p);
		int rootQ = root(q);
		if(rootP != rootQ){
			if(size[rootP] < size[rootQ]){
				parent[rootP] = rootQ;
				size[rootQ] = size[rootQ] + size[rootP];
			}else{
				parent[rootQ] = rootP;
				size[rootP] = size[rootP] + size[rootQ];
			}
			components--;
		}
	}
	
	// Returns true if p and q are connected (that is, if they are on the same component)	
	bool connected(int p, int q){
		return root(p) == root(q);
	}

	// Returns the number of components	
	int getComponents(){
		return components;
	}
};

int main(){
		// Create an Union-Find	with 5 nodes
		UnionFind uf(5);
		
		// Make some unions
		uf.unionElem(0, 2);
		uf.unionElem(1, 0);
		uf.unionElem(3, 4);
		
		// The number of components after these unions is:		
		int comp = uf.getComponents();
		cout<<"Components: "<<comp<<endl;
		// Are 1 and 2 on the same component?:		
		bool connected = uf.connected(1, 2);
		cout<<"Are 1 and 2 connected: "<<connected<<endl;
}
