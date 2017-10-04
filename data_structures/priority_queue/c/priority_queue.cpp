#include<stdio.h>
#include<malloc.h>
struct node{
	int data,priority;
	struct node* next;
};
struct node *header=NULL;

void enque(int data,int priority)
{
	struct node* ptr2;
	ptr2=(struct node*)malloc(sizeof(struct node));
	ptr2->data=data;
	ptr2->priority=priority;
	ptr2->next=header;
	header=ptr2;
}

void deque()
{
	struct node *ptr,*min,*prev;
	prev=NULL;
	ptr=header;
	min=ptr;
	ptr=ptr->next;
	if(ptr==NULL)
	{
		printf("empty\n");
		return;
	}
	while(ptr!=NULL)
	{
		if(min->priority>ptr->priority)
		{
			prev=min;
			min=ptr;
		}
		ptr=ptr->next;
	}
	printf("dequeued element: %d\tpriority: %d\n",min->data,min->priority);
	prev->next=min->next;
	free(min);
}

void display()
{
	struct node *ptr;
	ptr=header;
	if(ptr==NULL)
	{
		printf("empty\n");
		return;
	}
	while(ptr!=NULL)
	{
		printf("%d,%d\t",ptr->data,ptr->priority);
	ptr=ptr->next;
	}
	printf("\n");
}
int main()
{
	int c,x,p;
	while(1)
{
	printf("1.enque\n2.deque\n3.display\n4.exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:	printf("enter element and priority: ");
				scanf("%d%d",&x,&p);
				enque(x,p);
				break;
		case 2: deque();
				break;
		case 3: display();
				break;
		case 4: goto end;
	}
}
end:;
}

