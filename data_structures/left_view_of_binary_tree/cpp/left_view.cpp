/* A binary tree node
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
// A wrapper over leftViewUtil()
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
    printlevel(root->left,level+1,max_level);
    printlevel(root->right,level+1,max_level);
}

void leftView(Node *root){
    // Your code here
    int max_level=0;
    printlevel(root,1,&max_level);
}

