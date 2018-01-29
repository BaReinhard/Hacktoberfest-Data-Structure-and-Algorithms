namespace suffix_array {
	// 	RA[i][j] = Rank of suffix S[j...j + 2 ^ i] i.e. 2 ^ i length substring
	// 	starting at j.
	//	SA[i] = i’th Lexicographically smallest suffix’s index.

	int RA[LOGN][N], SA[N], tempSA[N], cnt[N], msb[N];
	int LCP[LOGN][N], dollar[N];

	void countingSort(int l, int k, int n){
		SET(cnt, 0);
		for(int i = 0; i < n; i++){
			int idx = (i + k < n ? RA[l][i + k] : 0);
			cnt[idx]++;
		}
		int maxi = max(300, n);
		for(int i = 0, sum = 0; i < maxi; i++){
			int t = cnt[i];
			cnt[i] = sum; 
			sum += t;
		}
		for(int i = 0; i < n; i++){
			int idx = SA[i] + k < n ? RA[l][SA[i] + k] : 0;
			tempSA[cnt[idx]++] = SA[i];
		}
		for(int i = 0; i < n; i++) SA[i] = tempSA[i];
	}
	void build_SA(string &s){
		int n = sz(s);
		for(int i = 0; i < n; i++) RA[0][i] = s[i];
		for(int i = 0; i < n; i++) SA[i] = i;
		for(int i = 0; i < LOGN - 1; i++){
			int k = (1 << i);
			if(k >= n)break;
			countingSort(i, k, n);
			countingSort(i, 0, n);
			int rank = 0;
			RA[i + 1][SA[0]] = rank;
			for(int j = 1; j < n; j++) {
				if(RA[i][SA[j]] == RA[i][SA[j - 1]] && RA[i][SA[j] + k] == RA[i][SA[j - 1] + k]) {
					RA[i + 1][SA[j]] = rank;
				} else {
					RA[i + 1][SA[j]] = ++rank;
				}
			}
		}
	}
	void build_msb() {
		int mx = -1;
		for(int i = 0; i < N; i++){
			if(i >= (1 << (mx + 1))) ++mx;
			msb[i] = mx;
		}
	}
	void build_LCP(string& s){
		int n = sz(s);
		for(int i = 0; i < n - 1; i++) { //Build the LCP array in O(NlogN)
			int x = SA[i], y = SA[i + 1], k, ret = 0;
			for(k = LOGN - 1; k >= 0 && x < n && y < n; k--) {
				if((1 << k) >= n) {
					continue;
				} if(RA[k][x] == RA[k][y]) {
					x += 1 << k, y += 1 << k, ret += 1 << k;
				}
			}
			if(ret >= dollar[SA[i]] - SA[i]) {
				ret = dollar[SA[i]] - SA[i];
			} 
			LCP[0][i] = ret;//LCP[i] shouldn’t exceed dollar[SA[i]]
		} //dollar[i] : index of dollar to the right of i.
		LCP[0][n - 1] = 10 * N;
		for(int i = 1; i < LOGN; i++){//Build the O(1) RMQ structure in O(NlogN)
			int add = (1 << (i - 1));
			if(add >= n)break; //small optimization
			for(int j = 0; j < n; j++) {
				if(j + add < n) {
					LCP[i][j] = min(LCP[i - 1][j], LCP[i - 1][j + add]);
				} else { 
					LCP[i][j] = LCP[i - 1][j];
				}
			}
		}	
	}
	int lcp(int x, int y){
		//O(1) LCP.x and y are indexes of the suffices in SUFFIX array..!!
		if(x == y) {
			return dollar[SA[x]]-SA[x];
		} if(x > y) {
			swap(x,y);
		} 
		--y;
		int idx = msb[y - x + 1], sub = (1 << idx);
		return min(LCP[idx][x], LCP[idx][y - sub + 1]);
	}
	bool equal(int i, int j, int p, int q){
		if(j - i != q - p) {
			return false;
		} 
		int idx = msb[j - i + 1], sub = (1 << idx);
		return (RA[idx][i] == RA[idx][p]) && RA[idx][j - sub + 1];
	} //Note : Do not forget to add a terminating ’$’
	// SET dollar array where dollar[i] is the next '$' in the string.
	// build_SA(s), build_LCP(s).  :))
}