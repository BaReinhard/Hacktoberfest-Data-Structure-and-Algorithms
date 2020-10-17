#include<stdio.h>
#include<stdlib.h>

void insertatbegin();
void deletefrombegin();
void insertatend();
void deletefromend();
void insertafterelement();
void deleteafterelement();
void print();

typedef struct NodeType
{
	int info;
	struct NodeType *next;
}node;

node *head = NULL;

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
		printf("\n5. Insert After Given element\n");
		printf("\n6. Delete After Given element\n");
		printf("\n7. Print\n");
		printf("\n8. Exit\n");
		
		printf("\nEnter UR Choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: insertatbegin(); break;
			case 2: deletefrombegin(); break;
			case 3: insertatend(); break;
			case 4: deletefromend(); break;
			case 5: insertafterelement(); break;
			case 6: deleteafterelement(); break;
			case 7: print(); break;
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
	
	if ( head == NULL)
	{
		ptr->next = NULL;
	}
	else
	{
		ptr->next = head;
	}
	
	head = ptr;
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
		
		head = ptr->next;
		
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
	ptr->next = NULL;
	
	if(head == NULL)
	{
		head = ptr;
	}
	else
	{
		loc = head;
		
		while(loc->next != NULL)
		{
			loc = loc->next;
		}
		
		loc->next = ptr;
	}
}

void deletefromend()
{
	node *ptr, *loc;
	
	if(head == NULL)
	{
		printf("\nLinked List is Empty\n");
	}
	else if(head->next == NULL)
	{
		ptr = head;
		printf("\nDeleted Element %d\n",ptr->info);
		head = NULL;
		free(ptr);
	}
	else
	{
		loc = head;
		ptr = loc->next;
		
		while(ptr->next != NULL)
		{
			loc = ptr;
			ptr = ptr->next;
		}
		loc->next = NULL;
		printf("\nDeleted Element %d\n",ptr->info);
		free(ptr);
	}
}

void insertafterelement()
{
	node *ptr, *loc;
	int after, v;
	
	if(head == NULL)
	{
		printf("\nLinked List is Empty\n");
	}	
	else
	{
		
		printf("\nEnter After Element\n");
		scanf("%d",&after);
		printf("\nEnter Element which u want to insert\n");
		scanf("%d",&v);
		
		loc = head;
		
		while(loc!=NULL)
		{
			if(loc->info == after)
			{
				break;
			}
			loc = loc->next;
		}
		
		if(loc == NULL)
		{
			printf("\nAfter Element Not Found\n");
		}
		else
		{
			ptr = (node *)malloc(sizeof(node));
			
			ptr->info = v;
			
			ptr->next = loc->next;
			loc->next = ptr;
		}
	}
	
}
void deleteafterelement()
{
	node *ptr, *loc;
	int after;
	
	if(head == NULL)
	{
		printf("\nLinked List is Empty\n");
	}	
	else
	{
		
		printf("\nEnter After Element\n");
		scanf("%d",&after);
		
		loc = head;
		
		while(loc!=NULL)
		{
			if(loc->info == after)
			{
				break;
			}
			loc = loc->next;
		}
		
		if(loc == NULL)
		{
			printf("\nAfter Element Not Found\n");
		}
		else
		{
			ptr = loc->next;
			loc->next = ptr->next;
			free(ptr);
		}
	}
}











