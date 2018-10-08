#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node()
    {
        next=NULL;
    }
};



int main()
{
    node *head=new node();
    node *temp=new node();
    cin>>temp->data;
    head=temp;
    cout<<"no of elements in linklist";
        for(int i=0;i<n-1;i++)
        {
          node *a=new node();
          cin>>a->data;
          temp->next=a;
          temp=a;    
        }
        temp->next=NULL;
      
    node *temp1=head;
    
    while(temp1!=NULL)
    {
       cout<<temp->data;
    }

    return 0;
}