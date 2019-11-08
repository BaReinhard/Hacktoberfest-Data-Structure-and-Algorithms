#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    int balance;
    struct node *left;
    struct node *right;
}Node;

int doubleRot = 0;
int simpleRot = 0;
int visitedNodes = 0;
int comparisons = 0;

int balanceFactor(Node *r);
Node *RightRotationSimple(Node *r);
Node *LeftRotationSimple(Node *r);

Node *CheckBalance(Node *r){
    int balance;
    balance= balanceFactor(r);
    if (balance < -1) {
        if (balanceFactor(r->left) > 0) {
            doubleRot++;
            r->left= LeftRotationSimple(r->left);
        }
        r= RightRotationSimple(r);
        simpleRot++;
    }
    else if (balance > 1) {
        if (balanceFactor(r->right) < 0) {
            doubleRot++;
            r->right= RightRotationSimple(r->right);
        }
        r= LeftRotationSimple(r);
        simpleRot ++;
    }
    return r;
}

Node *TreeInsert(Node *r, int num){
    if (r == NULL) {
        r= (Node *)malloc(sizeof(Node));
        r->key= num;                           
        r->right= NULL;                 
        r->left= NULL;                                  
    }
    else {
        visitedNodes ++;
                    
        if(num == r->key){
            return r;
        } else if (num < r->key) {   
            r->left= TreeInsert(r->left, num);
        } else {              
            r->right= TreeInsert(r->right, num);
        }
        r= CheckBalance(r);   
    }
    return r;
}

int TreeHeight(Node *r){
    if (r== NULL) {
        return -1;
    }
    else {
        int altLeft, altRight;
        altLeft= TreeHeight(r->left);
        altRight= TreeHeight(r->right);
        if (altLeft > altRight) {
            return altLeft + 1;
        }
        else {
            return altRight + 1;
        }
    }
}

int balanceFactor(Node *r){
    return TreeHeight(r->right) - TreeHeight(r->left);
}

Node *RightRotationSimple(Node *r){
    Node *q= r->left;
    r->left= q->right;
    q->right= r;
    return q;
}

Node *LeftRotationSimple(Node *r){
    Node *q= r->right;
    r->right= q->left;
    q->left= r;
    return q;
}

void PrintTree(Node* r){
    if(r){
        PrintTree(r->left);
        printf(" %d |", r->key);
        PrintTree(r->right);
    }
}

int main(){
    Node *root;
    root= NULL;

    root = TreeInsert(root, 10);
    root = TreeInsert(root, 20);
    root = TreeInsert(root, 14);
    root = TreeInsert(root, 8);       

    PrintTree(root);
}
