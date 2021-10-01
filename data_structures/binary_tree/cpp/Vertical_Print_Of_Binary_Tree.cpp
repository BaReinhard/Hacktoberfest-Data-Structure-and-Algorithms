#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

node *buildTreeUsingLevelOrderTraversal(vector<int> vec){
    queue<node*> q;
    node *root = new node(vec[0]);
    q.push(root);
    for(int i = 1; i < vec.size(); i+= 2)
    {
        node* temp = q.front();
        q.pop();
        if(vec[i] != -1){
            node *l = new node(vec[i]);
            q.push(l);
            temp->left = l;
        }
        if(vec[i+1] != -1){
            node *r = new node(vec[i+1]);
            q.push(r);
            temp->right = r;
        }
    }

    return root;
}

void levelOrderTraversal(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();
        if(temp == NULL){
            cout << endl;
            q.pop();
            if(!q.empty())
                q.push(NULL);
        }
        else{
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            cout << temp->data << " ";
        }
    }
}

void printAtLevelK(node* root, int k){
    if(root == NULL)
        return;
    if (k == 0){
        cout << root->data << " ";
        return;
    }
    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);

    return;
}

void traverseTree(node* root, int d, map<int, vector<int>> &m){
    if(root == NULL)
        return;
    m[d].push_back(root->data);
    traverseTree(root->left, d - 1, m);
    traverseTree(root->right, d + 1, m);

    return;

}

void verticalPrint(node *root){
    map<int, vector<int>> m;
    int d = 0;

    traverseTree(root, d, m);
    for(auto p: m){
        int key = p.first;
        vector<int> line = p.second;
        for(auto data: line)
            cout << data << " ";
        cout << endl;
    }
}


int main() {
    node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	root->right->left->right = new node(8);
	root->right->right->right = new node(9);

    verticalPrint(root);
}
