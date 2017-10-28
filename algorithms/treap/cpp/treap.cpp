#include<bits/stdc++.h>
using namespace std;

struct node
{
  int value,priority,sz,reverse;
  node *left,*right;
};
typedef node* pnode;
int getsize(pnode node)
{
  if(!node) return 0;
  return node->sz;
}
void refresh(pnode node)
{
  if (!node) return;
  node->sz=getsize(node->left)+getsize(node->right)+1;
}
void lazyupdate(pnode node)
{
  if(!node) return;
  if(node->reverse)
    {
      swap(node->left,node->right);
      if(node->left)
	node->left->reverse=1-node->left->reverse;
      if(node->right)
	node->right->reverse=1-node->right->reverse;
      node->reverse=0;
      refresh(node);
    }
}
void merge(pnode &result,pnode l ,pnode r)
{
  lazyupdate(l); lazyupdate(r);
  if(!l || !r)
    {
      result=(l?l:r);
      return;
    }
  if(l->priority>r->priority)
    {
      merge(l->right,l->right,r);
      result=l;
    }
  else
    {
      merge(r->left,l,r->left);
      result=r;
    }
  refresh(result);
}
void split(pnode node,pnode &l,pnode &r,int pos,int add)
{
  lazyupdate(node);
  if(!node)
    {
      l=r=node;
      return;
    }
  int curr_pos=add+getsize(node->left)+1;
  if(curr_pos<=pos)
    {
      split(node->right,node->right,r,pos,curr_pos);
      l=node;
    }
  else
    {
      split(node->left,l,node->left,pos,add);
      r=node;
    }
  refresh(node);
}
pnode create(int val)
{
  pnode temp=new node();
  temp->priority=rand();
  temp->sz=1;
  temp->left=temp->right=NULL;
  temp->value=val;
  temp->reverse=0;
  return temp;
}
void insert(pnode &node,int pos,int val)
{
  pnode l,r;
  split(node,l,r,pos-1,0);
  merge(l,l,create(val));
  merge(node,l,r);
}
int main()
{
  return 0;
}
