//WAP to find diameter of a BST.
#include<iostream>
#include<malloc.h>
using namespace std;
struct tree{
	int data;
	struct tree *left,*right;
};
typedef struct tree node;
node *current=NULL,*root=NULL,*parent=NULL,*temp=NULL;
void newnode(int n)
{
	current = (node*)malloc(sizeof(node));
	current->data = n;
	current->left = NULL;
	current->right = NULL;
	if(root==NULL)
	{
		root=current;
	}
	else
	{
		temp=root;
		parent=NULL;
		while(1)
		{	parent = temp;
			if(n<temp->data)
			{
				temp = temp->left;
				if(temp==NULL)
				{	parent->left= current;
					return;
				}
			}
			else
			{
				temp = temp->right;
				if(temp==NULL)
				{	parent->right= current;
					return;
				}
			}	
		}
	}
}
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int height(node* temp)
{
	if(temp==NULL)
	return 0;
	return 1+max(height(temp->left),height(temp->right));}
int diameter(node* temp)
{
	int dia=0,maxDia;
	if(temp ==NULL)
	return 0;
	int lheight,rheight,ldiameter,rdiameter;
	lheight = height(temp->left);
	rheight = height(temp->right);
	dia = 1 + lheight + rheight;
	ldiameter = diameter(temp->left);
	rdiameter = diameter(temp->right);
	maxDia = max(dia,max(ldiameter,rdiameter));
	return maxDia;
}
int main()
{
	int i,an;
	int x[]={41,27,83,45,65,80,40,55};
	/*
		   	 41
		    / \
		   27  83
		   \  /
		   40 45
		      \
		       65
		       / \
		     55  80
	*/
	for(i=0;i<=7;i++)
	newnode(x[i]);
	an=diameter(root);
	cout<<"\nDiameter of tree:"<<an;
	return 0;
}
