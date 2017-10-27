#include<bits/stdc++.h>
using namespace std;

class Node{

public:
    int d;
    Node* right;
    Node* left;
    Node(int d){
        this->d=d;
        left=NULL;
        right=NULL;
    }
};

Node* buildTree(){

    int d;
    cin>>d;
    queue<Node*> q;
    Node* n=new Node(d);
    q.push(n);

    while(!q.empty()){
        Node* root=q.front();
        q.pop();
        int d1,d2;
        cin>>d1>>d2;
        if (d1!=-1){
            Node* n=new Node(d1);
            root->left=n;
            q.push(n);
        }
        if (d2!=-1){
            Node* n=new Node(d2);
            root->right=n;
            q.push(n);
        }
    }
    return n;
}

void InOrder(Node* root){

    if (root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->d<<" ";
    InOrder(root->right);
}


void printRight(Node* root,int level,int &maxLevel){

    if (root==NULL){
        return;;
    }

    if (level>maxLevel){
        cout<<root->d<<" ";
        maxLevel=level;
    }

    printRight(root->right,level+1,maxLevel);
    printRight(root->left,level+1,maxLevel);

}

void RightView(Node* root){
    int maxLevel=0;
    printRight(root,1,maxLevel);
}

//Main function
int main(){

    Node* root=buildTree();
    RightView(root);

}