/* 
	Code to construct the Block Cut Tree of a graph in O(n) time and memory
	Code used for competitve programming on codeforces. (Accepted Code).
	Block Cut Tree / Cut - Vertex tree: Tree constructed by components split by the articulation vertices.
*/
const int N = (int)1e5 + 10;
// N jitna n hai uska double rakhna
vector < int > g[N], cutVtree[N], st;	// g[v]: vector of all the adjacent edges;
int a[N], b[N], compNo[N], col[N], low[N], in[N], L[N], extra[N], tim, C;
bool cutV[N];

int adj(int u, int i) {
	return a[i] ^ b[i] ^ u;
} 
void dfs(int v) {
	int ch = 0;
	low[v] = in[v] = tim++;
	for(int e: g[v]) {
		int u = adj(v, e);
		if (in[u] == -1) {
			L[u] = L[v] + 1, st.push_back(e), dfs(u);
			low[v] = min(low[v], low[u]);
			if (in[v] == 0 || low[u] >= in[v]) {
				if (in[v]||ch) cutV[v] = true;
				++C;
				while(sz(st)) {
					int ed = st.back();
					col[ed] = C, st.pop_back();
					if (ed == e) break;
				}
			}
		} else if (L[u] < L[v] - 1) { // back-edge.
			low[v] = min(low[v], in[u]), st.push_back(e);
		}
		++ch;
	}
	return;
} 
void run(int n) {
	SET(low, -1); SET(L,-1);
  	SET(in, -1); SET(col, -1); SET(cutV, false); st.resize(0); C = 0;
	for(int i = 1; i <= n; ++i) if (in[i] == -1) tim = 0, dfs(i);
} 
void build_tree(int n) {
	run(n);
	SET(compNo, -1);
	vector < int > temp;
	SET(extra, -1);
	for(int i = 1; i <= n; ++i) {
		temp.clear();
		for(int e: g[i]) {
			temp.push_back(col[e]);
	    }
	    sort(all(temp));
	    temp.erase(unique(all(temp)), temp.end());
	    if (temp.empty()) {
	    	compNo[i] = C + i, extra[C + i] = 0;
	    } else if (sz(temp) == 1) { // belongs to only 1 component.
	    	compNo[i] = temp[0], extra[temp[0]] = 1;
	    } else { // cutVertex
	    	compNo[i] = C + i, extra[C + i] = 0;
	    	for(int u: temp) {
	    		extra[u] = 0;
	    		cutVtree[C + i].push_back(u);
	    		cutVtree[u].push_back(C + i);
	    	}
	    }
	}
	return;
}
void show_tree(int n) {
	for(int i = 1; i <= n; ++i) {
		if (sz(cutVtree[i])) {
			trace(i);
			for(int u: cutVtree[i]) cout << u << ' ';
			cout << endl;
		}
	}
	return;
}