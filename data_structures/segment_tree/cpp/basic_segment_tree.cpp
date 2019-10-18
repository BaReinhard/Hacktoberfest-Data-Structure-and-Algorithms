#include <bits/stdc++.h>

using namespace std;

struct node{
	int ans;
};

struct node combine(struct node a,struct node b){
	struct node c;
	c.ans=a.ans+b.ans;
	return c;
}

struct node query(struct node *tree,int l,int r,int ql,int qr,int treenode){
	struct node tem;
	tem.ans=0;
	if(qr<l||ql>r)
		return tem;
	if(l>=ql&&r<=qr)
		return tree[treenode];

	int mid = (l+r)>>1;
	
	struct node first = query(tree,l,mid,ql,qr,2*treenode);
	struct node second = query(tree,mid+1,r,ql,qr,2*treenode+1);
	struct node third = combine(first,second);
	return third;
}

void buildtree(long long *a,struct node *tree,int l,int r,int treenode){
	if(l==r){
		tree[treenode].ans=a[l];
		return;
	}
	int mid=(l+r)>>1;
	buildtree(a,tree,l,mid,2*treenode);
	buildtree(a,tree,mid+1,r,2*treenode+1);

	tree[treenode]=combine(tree[2*treenode],tree[2*treenode+1]);
}

int main(void){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.flush();

	int n;
	cin >> n;
	long long a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	struct node tree[4*n];

	buildtree(a,tree,0,n-1,1);

	int m;
	cin >> m;
	for(int i=0;i<m;i++){
		int l,r;
		cin >> l >> r;
    long long ans = query(tree,0,n-1,l-1,r-1,1).ans;
    cout << ans << endl;	
	}
}
