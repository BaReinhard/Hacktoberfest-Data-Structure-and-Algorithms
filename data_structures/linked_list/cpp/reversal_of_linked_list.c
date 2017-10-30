#include<stdio.h>
#include<malloc.h>
//Declaring a node.
struct Node
{
	int data; //data part of node.
	struct Node *link; //pointer to next node.
};

struct Node *header;  //First Node of list.(global)

//creation of linkedlist
void createlist(int n)
	{
			struct Node *temp=header;	
			temp=(struct Node*)malloc(sizeof(struct Node)); //allocating memory to first node.
			if(temp==NULL)
			printf("Overflow"); //if there is no space in memory
			temp->link=NULL;
			int i=1;
			printf("Enter The Value Of Node%d: ",i);
			scanf("%d",&temp->data);
			if(header==NULL)
			{
				temp->link=NULL;
				header=temp;
			}
	         i=i+1;
		while(i<=n)
		{
			struct Node* temp1=temp;
			temp=(struct Node*)malloc(sizeof(struct Node)); //allocating memory to second node.
			if(temp==NULL)
			printf("Overflow");
			printf("Enter The Value for Node%d: ",i);
			scanf("%d",&temp->data);
			temp1->link=temp;
			temp->link=NULL;
			i=i+1;
		}
	
	
	}

//display of linkedlist
void displaylist()
	{
		struct Node* temp=header;
		printf("\nElements Of List:");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->link;
		}

	}
//function to reverselist	
void reverse()
	{
		struct Node*prev=NULL;
		struct Node* temp=header;
		struct Node*next;
		while(temp!=NULL)
		{
			next=temp->link;
			temp->link=prev;
			prev=temp;
			temp=next;
		}
		header=prev;
		printf("\n\nAfter Reversing\n ");
		displaylist();
	}	
	
	
//Main Body
int main()
{
	int num;
	printf("Enter The Number Of Nodes For Linkedlist: ");
	scanf("%d",&num);
	createlist(num);//call to createlist
	displaylist();//call to displaylist
	reverse();//call to reverse list
}
