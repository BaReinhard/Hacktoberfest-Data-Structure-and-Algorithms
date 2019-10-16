#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

typedef struct btree {
	int data;
	struct btree *left;
	struct btree *right;
}btree;

btree *makeTree(btree *root , int d) {
	btree *nn = (btree*)malloc(sizeof(btree));
	nn->data = d;
	nn->left = NULL;
	nn->right = NULL;
	if(root==NULL) {
		return nn;
	}
	else {
		queue<btree*> q;
		q.push(root);
		while(!q.empty()) {
			btree *node = q.front();
			q.pop();
			if(node->left) q.push(node->left);
			else {
				node->left = nn;
				return root;
			}

			if(node->right) q.push(node->right);
			else {
				node->right = nn;
				return root;
			}
		}
	}
}

btree *mirror(btree *root) {
	if(root==NULL) return NULL;
	btree *nn = (btree*)malloc(sizeof(btree));

	nn->data = root->data;
	nn->right = mirror(root->left);
	nn->left = mirror(root->right);

	return nn;
}

void printTreeLevelOrder(btree *root) {
	queue<btree*> q;
	q.push(root);
	while(!q.empty()) {
		btree *node = q.front();
		q.pop();
		cout<<node->data<<" ";
		if(node->left) q.push(node->left);

		if(node->right) q.push(node->right);
	}
}

int main()
{
	btree *a = NULL;
	a = makeTree(a,1);
	a = makeTree(a,2);
	a = makeTree(a,3);
	a = makeTree(a,4);
	a = makeTree(a,5);
	a = makeTree(a,6);
	a = makeTree(a,7);

	btree *b = mirror(a);
	printTreeLevelOrder(b);
	cout<<endl;
	return 0;
}
