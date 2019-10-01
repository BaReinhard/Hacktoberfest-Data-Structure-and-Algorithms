/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
void left(Node* root){
    if(root==NULL)
        return;
    if(root->left!=NULL && root->right!=NULL){
        cout<<root->data<<" ";
        left(root->left);
    }
    if(root->left!=NULL && root->right==NULL){
        cout<<root->data<<" ";
        left(root->left);
    }
    if(root->left==NULL && root->right!=NULL){
        cout<<root->data<<" ";
        left(root->right);
    }
    if(root->right==NULL && root->left==NULL)
        return;
}

void midleaves(Node *root){
    if(root==NULL)
        return;
    midleaves(root->left);
    midleaves(root->right);
    if(root->left==NULL && root->right==NULL)
        cout<<root->data<<" ";
}

void right(Node* root){
    if(root==NULL)
        return;
    if(root->left!=NULL && root->right!=NULL)
        right(root->right);
    if(root->left!=NULL && root->right==NULL)
        right(root->left);
    if(root->left==NULL && root->right!=NULL)
        right(root->right);
    if(root->right==NULL && root->left==NULL)
        return;
    cout<<root->data<<" ";
}

void printBoundary(Node *root){
    //Your code here
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    left(root->left);
    midleaves(root);
    right(root->right);
}
