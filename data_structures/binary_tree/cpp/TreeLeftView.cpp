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

unordered_map<int,Node*> m;

void PrintLeftView(Node* root){
    if (root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;

    while(!q.empty()){

        Node* root1=q.front();
        if (root1==NULL){
            q.pop();
            if (!q.empty()){
                level++;
                q.push(NULL);
            }
        }
        else{
            if(!(m.count(level))){
                m[level]=root1;
                while(q.front()!=NULL){
                    q.pop();
                }
            }
            if (root1->left){
                q.push(root1->left);
            }
            if (root1->right){
                q.push(root1->right);
            }
        }
    }
}

void PrintMap(){

    for (int i = 0; i <m.size() ; ++i) {
        cout<<m[i]->d<<" ";
    }

}

//Main function
int main(){

    Node* root=buildTree();
    //InOrder(root);

    PrintLeftView(root);
    PrintMap();


}