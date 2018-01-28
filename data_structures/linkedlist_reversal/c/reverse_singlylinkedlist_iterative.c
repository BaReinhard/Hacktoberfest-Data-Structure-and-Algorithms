#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void main()
{
	struct node *p, *ptr, *head = NULL;
	int i, j, n;
	printf("(Size of a node: %lu)\n", sizeof(struct node));
	printf("Enter the number of terms: ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		ptr = (struct node *)malloc(sizeof(struct node));
		printf("Enter the data: ");
		scanf("%d", &ptr->data);
		ptr->next = NULL;
		if(head == NULL)
		{
			head = ptr;
		}
		else
		{
			p->next = ptr;
		}
		p = ptr;
	}
	ptr = head;
	p = head;
	printf("Before reversing the singly linked list:\n");
	while(ptr->next != NULL)
	{
		printf("%d -- ", ptr->data);
		ptr = ptr->next;
	}
	printf("%d -- \n", ptr->data);
	//code to print linked list in reverse order
	printf("Linked list in reverse order: \n");	
	while(ptr != head)
	{
		p = head;
		printf("%d -- ", ptr->data);
		while(p->next != ptr)
			p = p->next;
		ptr = p;	
	}
	printf("%d\nEnd\n", ptr->data);
}

