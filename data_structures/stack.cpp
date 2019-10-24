#include<iostream>

using namespace std;


int stac[100];int n=100;int top=-1;
void display();
void push(int);
void pop();
bool isemt();
bool isfull();


int main()
{
int ch,s;
char c;

x1:
cout<<"\nEnter a choice for stack:\n1. add an element\n2. delete an element\n3.display the content";
cin>>ch;

switch(ch)
{
case 1:
 cout<<"\nEnter the element:";
 cin>>s;
 if(isfull())
 {
  cout<<"\nStack is full,cannot enter";
 }
 else 
 push(s);
 cout<<"\noperation successful";
 break;
case 2:
 if(isemt())
 { 
  cout<<"\nStack already empty";
 }
 else
 pop();
 cout<<"operation successful";
 break;
case 3:
 display();
 default:
  cout<<"\nwrong choice";
}
 cout<<"\nDo you want to continue(y/n):";
 cin>>c;
if(c=='Y'||c=='y')
goto x1;


return 0;
}

void display()
{

 if(top<=-1)
  cout<<"No element ";
 else 
 { int k=top;
  cout<<"\nstack :";
  while(k>=0)
  {
   cout<<stac[k]<<" ";
   k--;
  }
  
 }
}



void push(int m)
{
 if(top>=100) 
  cout<<"\nstack overflow";
 else
 {
  stac[++top]=m; 
 }
}

void pop()
{
 if(top<=-1)
 cout<<"Stack Underflow";
 else
 {stac[top]=0;
 top--;
 }
}


bool isemt()
{
  if(top==-1)
  return true;
  else 
  return false;
}

bool isfull()
{

  if(top==n)
  return true;
  else 
  return false;
}
