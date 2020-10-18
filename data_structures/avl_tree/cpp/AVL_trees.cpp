#include<iostream>

using namespace std;

struct AVLNode{
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

AVLNode* Get_new_node(int data){
    AVLNode* temp = new AVLNode();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 0;
    return temp;
}

int height(AVLNode* root){
    if (root == NULL){
        return 0;
    }
    return root->height;
}

AVLNode* RightRotate(AVLNode* y){
    // Basic definitions
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    // rotation 
    x->right = y;
    y->left = T2;
    //height updates
    x->height = (height(x->left), height(x->right)) + 1;
    y->height = (height(y->left), height(y->right)) + 1;
    return x;
}

AVLNode* LeftRotate(AVLNode* y){
    // Basic definitions
    AVLNode* x = y->right;
    AVLNode* T2 = x->left;
    // rotation 
    x->left = y;
    y->right = T2;
    //height updates
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

int getBalance(AVLNode* root){
    if(root == NULL){
        return 0;
    }
    return height(root->left) - height(root->right);
}

AVLNode* Insert(AVLNode* root, int data){
    // basic recursion(traversing along the heights to the place where u need to insert the node and also go 
    // up to the ancestors while balancing the tree)
    if (root == NULL){
        return Get_new_node(data);
    }else if(data <= root->data){
        root->left = Insert(root->left, data);
    }else{
        root->right = Insert(root->right, data);
    }
    // updation of height of root is necessary 
    root->height = max(height(root->left), height(root->right)) + 1;
    // balance must be refereshed and computed every time
    int balance = getBalance(root);
    
    // based upon the balances we will decide the need of rotation and type of rotation decided by the structure 
    // LL rotation
    if(balance>1 && data < root->left->data){
        return RightRotate(root);
    }
    // RR rotation
    else if(balance<-1 && data > root->right->data){
        return LeftRotate(root);
    }
    // LR rotation
    else if(balance>1 && data > root->left->data){
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    // RL rotation
    else if(balance<-1 && data < root->right->data){
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }
    return root;
}



int main(){
    AVLNode *root = NULL;  
      
    /* Constructing tree given in  
    the above figure */
    root = Insert(root, 10);  
    root = Insert(root, 20);  
    root = Insert(root, 30);  
    root = Insert(root, 40);  
    root = Insert(root, 50);  
    root = Insert(root, 25);  
    return 0;
}