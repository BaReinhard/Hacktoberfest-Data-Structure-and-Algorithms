
class UnionFind{
	private int[] parent, size;
	private int components;
	
	// Creates the Union-Find data structure
	// n = number of nodes	 
	public UnionFind(int n){
		components = n;
		parent = new int[n];
		size = new int[n];
		for(int i=0; i<n; i++){
			parent[i] = i;
			size[i] = 1;
		}
	}

	// Finds the root of p, which is the identifier of its component	
	private int root(int p){
		while(p != parent[p]){
			parent[p] = parent[parent[p]];
			p = parent[p];
		}
		return p;
	}

	// Merges the component containing p and the component containing q	
	public void union(int p, int q){
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
	public boolean connected(int p, int q){
		return root(p) == root(q);
	}

	// Returns the number of components	
	public int getComponents(){
		return components;
	}
}

class Main {
	public static void main(String[] args){		
		// Create an Union-Find	with 5 nodes
		UnionFind uf = new UnionFind(5);
		
		// Make some unions
		uf.union(0, 2);
		uf.union(1, 0);
		uf.union(3, 4);
		
		// The number of components after these unions is:		
		int comp = uf.getComponents();

		// Are 1 and 2 on the same component?:		
		boolean connected = uf.connected(1, 2);
	}
}
