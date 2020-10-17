#include<stdio.h>
#include<stdlib.h>

void insertatbegin();
void deletefrombegin();
void insertatend();
void deletefromend();
void print();

typedef struct NodeType
{
	struct NodeType *prev;
	int info;
	struct NodeType *next;
}node;

node *head = NULL;
node *tail = NULL;

int main()
{
	int ch;
	
	while(1)
	{
		printf("\nMENU\n");
		printf("\n1. Insert At Begin\n");
		printf("\n2. Delete From Begin\n");
		printf("\n3. Insert At End\n");
		printf("\n4. Delete From End\n");
		printf("\n5. Print\n");
		printf("\n6. Exit\n");
		
		printf("\nEnter UR Choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: insertatbegin(); break;
			case 2: deletefrombegin(); break;
			case 3: insertatend(); break;
			case 4: deletefromend(); break;
			case 5: print(); break;
			default : exit(0);
		}
	}
	
	return 0;
}

void insertatbegin()
{
	int v;
	node *ptr;
	
	printf("\nEnter Value which U want to Insert\n");
	scanf("%d",&v);
	
	ptr = (node *) malloc (sizeof(node));
	
	ptr->info = v;
	
	if (head == NULL)
	{
		ptr->next = ptr->prev = NULL;
		head = tail = ptr;
	}
	else
	{
		ptr->prev = NULL;
		ptr->next = head;
		head->prev = ptr;
		head = ptr;
	}
}
void deletefrombegin()
{
	node *ptr;
	
	if (head == NULL)
	{
		printf("\nLinked List is Empty\n");
	}
	else
	{
		ptr = head;
		
		printf("\nDeleted Element is : %d",ptr->info);
		
		if(head == tail)
		{
			head = tail = NULL;
		}
		else
		{
			(ptr->next)->prev = NULL;
			head = ptr->next;			
		}	
		free(ptr);
	}
}
void print()
{
	node *ptr;
	
	if (head == NULL)
	{
		printf("\nLinked List is Empty\n");
	}
	else
	{
		ptr = head;
		
		while (ptr != NULL)
		{
			printf("%d ",ptr->info);
			ptr = ptr->next;
		}
	}
}

void insertatend()
{
	int v;
	node *ptr, *loc;
	
	printf("\nEnter Value which U want to Insert\n");
	scanf("%d",&v);
	
	ptr = (node *) malloc (sizeof(node));
	ptr->info = v;
		
	if(head == NULL)
	{
		ptr->next = ptr->prev = NULL;
		head = tail = ptr;
	}
	else
	{
		ptr->next = NULL;
		ptr->prev = tail;
		tail->next = ptr;
		tail = ptr;
	}
}

void deletefromend()
{
	node *ptr, *loc;
	
	if(head == NULL)
	{
		printf("\nLinked List is Empty\n");
	}
	else
	{
		ptr = tail;
		
		if(head == tail)
		{
			head = tail = NULL;
		}
		else
		{
			(ptr->prev)->next = NULL;
			tail = ptr->prev;
		}
		free(ptr);
	}
	
}





			
