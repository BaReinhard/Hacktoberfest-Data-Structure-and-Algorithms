/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
// Should print right view of tree
int height(Node *root){
    if(root==NULL)
        return 0;
    int lheight=height(root->left);
    int rheight=height(root->right);
    if(lheight>rheight)
        return lheight+1;
    else
        return rheight+1;
}

void printlevel(Node *root, int level, int *max_level){
    if(root==NULL)
        return;
    if(*max_level<level){
        cout<<root->data<<" ";
        *max_level=level;
    }
    printlevel(root->right,level+1,max_level);
    printlevel(root->left,level+1,max_level);
}

void rightView(Node *root){
   // Your Code here
    int max_level=0;
    printlevel(root,1,&max_level);
    
}

