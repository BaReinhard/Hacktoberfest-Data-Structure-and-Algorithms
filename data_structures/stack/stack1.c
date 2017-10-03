#include<stdio.h>
#include<stdlib.h>


struct node{
 int data;
struct node* next;
};

struct node* head;
void insertatthebegin(int x)
{
 struct node* temp=(struct node*)malloc(sizeof(struct node));
 temp->data=x;
 temp->next=head;
 head=temp;
 
}


void print()
{
 struct node* temp=head;
 
if(temp== NULL)
 printf("empty list\n");
else{
 while(temp!=NULL)
   {
    printf("%d ",temp->data);
    temp=temp->next;
   }
}
printf("\n"); 
 
}


void reverse()
{
 struct node* prev, *current , *next;
 prev=NULL;

current=head;

while(current !=NULL)
{
 next=current->next;
 current->next=prev;
 prev=current;
current=next;
}
head=prev;

}

int main()
{
int i,j,n,k,l,x;
 head=NULL;
printf("enter the number of elements\n");
scanf("%d",&n);

printf("enter the elements and the position\n");
for(i=0;i<n;i++)
{
 scanf("%d",&x);
 insertatthebegin(x);
//print();
}
print();

reverse();
 printf("the reversed linked list is \n");
print();


return 0;
}


