#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        data =d;
        left = NULL;
        right = NULL;
    }
};

node* insertInBST(node* root, int data)
{
    if(root==NULL)
    return new node(data);

    if(root->data>=data)
    {
        root->left = insertInBST(root->left, data);
    }

    else
    {
        root->right = insertInBST(root->right, data);
    }
   return root;

}
node* buildTree()
{
    int d;
    cin>>d;
    
    node* root = NULL;
    while(d!=-1)
    {
       root = insertInBST(root, d);
       cin>>d;
    }
    return root;
}

void bfs(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* f = q.front();

        if(f==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            cout<<f->data<<" ";
            if(f->left)
            q.push(f->left);

            if(f->right)
            q.push(f->right);
        }
    }
}
class HTPair //each node will return head and tail of the linked list
{
   public:
   node* head;
   node* tail;
};

//we will be using post order traversal
//left right root
HTPair flatten(node* root)
{
    HTPair p;
    if(root==NULL)
    {
        p.head = NULL;
        p.tail = NULL;
        return p;
    }
    
    //if the node is leaf node
    if(root->left==NULL && root->right==NULL)
    {
        p.head = root;
        p.tail = root;
        return p;
    }

    //if left subtree is not null but right subtree is null
    if(root->left!=NULL && root->right==NULL)
    {
        HTPair leftLL = flatten(root->left);
        //instead of next pointer, we will have right pointer
        leftLL.tail->right = root;
        //now new head will be head of left linked list
        //and new tail will be root itself
        p.head =  leftLL.head;
        p.tail = root;
        return p;
    }

    //if right subtree is not null but left subtree is null
    //then root will point to head of the right subtree's Linked list 

    if(root->right!=NULL && root->left==NULL)
    {
        HTPair rightLL = flatten(root->right);
        root->right = rightLL.head;
        p.head = root;
        p.tail = rightLL.tail;
        return p;
    }

    //else the case when both left subtree and right subtrees are not null
    //then tail of left subtree will be pointing to root
    //and root will point to head of right subtrees linked list

    HTPair leftLL = flatten(root->left);
    HTPair rightLL = flatten(root->right);
    leftLL.tail->right = root;
    root->right = rightLL.head;
    p.head = leftLL.head;
    p.tail = rightLL.tail;
    return p;
}
int main()
{
  node* root = buildTree();
  bfs(root);
  cout<<endl;

  HTPair p = flatten(root);
  node* temp = p.head;
  while(temp!=NULL)
  {
      cout<<temp->data<<"->";
      temp = temp->right;
  }
}
