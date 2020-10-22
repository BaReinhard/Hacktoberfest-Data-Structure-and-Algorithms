#include<stdio.h>

#include<stdlib.h>


typedef struct node
{
	int data;
	struct node * next;

}node;


void insert(int val);
void delete();
void peep();
void display();
struct node * front=NULL;
struct node * rear=NULL;

int main()
{
	int val,ch;
	
	while(1)
	{
		printf("\n1.INSERT 2.DELETE 3.PEEP 4.DISPLAY 5.EXIT\n Enter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("Enter the value:");
				scanf("%d",&val);
				insert(val);
				break;
			case 2:
				delete();
				break;
			case 3:
				peep();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
				
		
		}
		
	
	
	}
	
	
	return 0;

}

void insert(int val)
{
	node * newnode=(node *)malloc(sizeof(node));
	newnode->data=val;
	if(front==NULL)
	{
		front=rear=newnode;
		newnode->next=NULL;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
		newnode->next=NULL;
	
	}


}

void delete()
{
	node * ptr;
	if(front==NULL)
	{
		printf("The queue is empty.");
	
	}
	else
	{
		ptr=front;
		front=ptr->next;
		free(ptr);
	
	}

}

void peep()
{	
	if(front==NULL)
	{
		printf("The queque is empty.");
	}
	else
	{
	
		printf("The element is %d",front->data);
	}
}


void display()
{
	node * ptr;
	ptr=front;
	
	if(ptr==NULL)
	{
		printf("Linked list empty.");
	}
	else
	{
		printf("\nElements of the list are:");
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
	}




}

