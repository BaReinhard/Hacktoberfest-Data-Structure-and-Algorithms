#include<iostream>
using namespace std;
struct node
{
    struct node *pre;
    int data;
    struct node *next;
}*f=NULL;
void create(int a[],int n)
{
    struct node *t,*last;
    f=new node;
    f->data=a[0];
    f->pre=0;
    f->next=0;
    last=f;
    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=last->next;
        t->pre=last;
        last->next=t;
        last=t;
    }
}
void display(struct node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
int length(struct node *p)
{
    int len=0;
    while(p!=0)
    {
        len++;
        p=p->next;
    }
    return len;
}
void insert(struct node *p,int index,int x)
{
    struct node *t;
    if(index==0)
    {
        t=new node;
        t->data=x;
        f->pre=t;
        t->pre=0;
        t->next=f;
        f=t;
    }
    else
    {
        for(int i=1;i<index-1;i++)
            p=p->next;
        t=new node;
        t->data=x;
        t->pre=p;
        t->next=p->next;
        if(p->next)
            p->next->pre=t;
        p->next=t;
    }
}
int delet(struct node *p,int index)
{
    int x=-1;
    if(index<1&&index>length(p))
        return -1;
    if(index==1)
    {
        f=f->next;
        f->pre=0;
        x=p->data;
        delete p;
    }
    else{
        for(int i=1;i<index;i++)
            p=p->next;
        p->pre->next=p->next;
        if(p->next)
            p->next->pre=p->pre;
        x=p->data;
        delete p;
    }
    return x;
}
void reverse(struct node *p)
{
    struct node *temp;
    while(p!=0){
    temp=p->next;
    p->next=p->pre;
    p->pre=temp;
    p=p->pre;
    if(p!=0&&p->next==0)
        f=p;
    }
}
int main()
{
    int a[10];
    cout<<"enter elements of link list";
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    create(a,10);
    display(f);
    cout<<endl;
    cout<<length(f);
    cout<<endl;
    insert(f,3,33);
    display(f);
    delet(f,4);
    cout<<endl;
    display(f);
    reverse(f);
    cout<<endl;
    display(f);

}
