struct ahocorasick {
  	vector <int> sufflink, out;
  	vector< map<char, int> > trie;
  	int sz;
  	ahocorasick() {
	    sz = 0, out.resize(1), trie.resize(1);
	}
	// insertion in trie. (supports duplicate strings)
  	inline void insert(string &s) {
    	int curr = 0;
    	for(auto ch: s) {
	    	if(!trie[curr].count(ch)) {
			    trie[curr][ch] = ++sz;
			    trie.PB(map<char,int>());
			    out.PB(0);
			}
			curr = trie[curr][ch];
		}
		out[curr]++;
	}
	inline void build_automation() {
    	sufflink.resize(sz+3);
    	queue<int> q;
	    for(auto x : trie[0]) {
			sufflink[x.S]=0;
			q.push(x.S);
		}
	    while(!q.empty()) {
			int curr = q.front();
			q.pop();
			for(auto x : trie[curr]) {
			    q.push(x.S);
			    int tmp = sufflink[curr];
			    while(!trie[tmp].count(x.F) && tmp) tmp = sufflink[tmp];
			    if(trie[tmp].count(x.F)) sufflink[x.S] = trie[tmp][x.F];
			    else sufflink[x.S] = 0;
			    out[x.S] += out[sufflink[x.S]];
			}
		}
  	}
	inline int findnextstate(int curr, char ch) {
	    while(curr && !trie[curr].count(ch)) curr = sufflink[curr];
	    if (trie[curr].count(ch) > 0) curr = trie[curr][ch];
	    return curr;
	}
  	inline void clear() {
    	trie.clear(); sufflink.clear(); out.clear(); out.resize(1); trie.resize(1); 
    	sz = 0;
  	}
};
