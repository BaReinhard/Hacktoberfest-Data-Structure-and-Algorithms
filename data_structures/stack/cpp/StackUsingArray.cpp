#include<iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    int *s;
};
void create(struct stack *st)
{
    cout<<"enter stack size";
    cin>>st->size;
    st->top=-1;
    st->s=new int[st->size];
}
void display(struct stack *st)
{
    for(int i=st->top;i>=0;i--)
        cout<<st->s[i]<<" ";
}
void push(struct stack *st,int x)
{
    if(st->top==st->size-1)
        cout<<"stack is full";
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}
int pop(struct stack *st)
{
    int x=-1;
    if(st->top==-1)
        cout<<"stack is underflow";
    else
    {
        x=st->s[st->top];
        st->top--;
    }
    return x;
}
int peek(struct stack *st,int pos)
{
    int x=-1;
    if(st->top-pos+1<0)
        cout<<"invalid index";
    else
    {
        x=st->s[st->top-pos+1];
    }
    return x;
}
int isempty(struct stack *st)
{
    if(st->top==-1)
        return 1;
    else
        return 0;
}
int isfull(struct stack *st)
{
    if(st->top==st->size-1)
        return 1;
    else
        return 0;
}
int stacktop(struct stack *st)
{
    if(!isempty(st))
        return st->s[st->top];
    return 0;
}
int main()
{
    struct stack st;
    create(&st);
    push(&st,3);
    push(&st,5);
    push(&st,6);
    push(&st,7);
    push(&st,9);
    display(&st);
    cout<<endl;
    cout<<pop(&st)<<endl;
    display(&st);
    cout<<endl;
    cout<<pop(&st)<<endl;
    display(&st);
    cout<<endl;
    cout<<pop(&st)<<endl;
    display(&st);
    cout<<endl;
    cout<<pop(&st)<<endl;
    display(&st);
    cout<<endl;
    cout<<pop(&st)<<endl;
    display(&st);
    cout<<endl;
    cout<<pop(&st)<<endl;
    display(&st);
    push(&st,3);
    push(&st,5);
    push(&st,6);
    push(&st,7);
    push(&st,9);
    display(&st);
    cout<<endl;
    cout<< peek(&st,2)<<endl;
    cout<<isempty(&st)<<endl;
    cout<<isfull(&st)<<endl;
    cout<<stacktop(&st);
}
