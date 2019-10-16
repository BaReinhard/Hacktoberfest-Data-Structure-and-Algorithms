#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
	int info;
	struct node *next;
}*start=NULL;

int main()
{
	int n;
	char ch;
	do
	{
		printf("enter choice\n");
		printf("1.creation\n2.insertion\n3.deletion\n4.search\n5.display\n");
	    scanf("%d",&n);
		switch(n)
		{
			case '1' : create();
				break;
			case '2' : insert();
				break;
			case '3' : delete();
				break;
			case '4' : search();
				break;
			case '5' : display();
				break;
			default:printf("wrong choice\n");
				break;
		}
	    printf("\nwant to continue\n");
        scanf("%s",&ch);
    }while(ch!='n');
    return 0;
}

void create()
{
	struct node *temp,*new;
	char ch;
	do
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\nenter data\n");
		scanf("%d",&temp->info);
		if(start==NULL)
		{
			start=temp;
			temp->next=NULL;
			new=temp;
		}
		else
		{
			new->next=temp;
			temp->next=NULL;
			new=temp;
		}
		printf("want to enter more\n");
		ch=getche();
		printf("\n");
	}while(ch!='n');
}

void insert()
{
	int n;
	struct node *ptr,*temp;
	printf("enter choice\n");
	printf("1.insertion at beginning\n2.insertion in the middle\n3.insertion at end\n");
	scanf("%d",&n);
	if(n==1)
	{
		printf("enter the data to be inserted at the beginning\n");
		temp=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&temp->info);
		temp->next=start;
		start=temp;
	}
	else if(n==2)
	{
		int i,pos;
		ptr=start;
		printf("insert data after the position\n");
		scanf("%d",&pos);
		for(i=0;i<pos-1;i++)
			ptr=ptr->next;
		temp=(struct node*)malloc(sizeof(struct node));
		printf("enter data to be entered\n");
		scanf("%d",&temp->info);
		temp->next=ptr->next;
		ptr->next=temp;
	}
	else if(n==3)
	{
		printf("enter data to be inserted at the end\n");
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		temp=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&temp->info);
		temp->next=NULL;
		ptr->next=temp;
	}
}

void delete()
{
	int n;
	struct node *ptr,*temp;
	ptr=start;
	printf("enter choice\n");
	printf("1.deletion at the beginning\n2.deletion in the middle\n3.deletion at the end\n");
	scanf("%d",&n);
	if(n==1)
	{
		start=ptr->next;
		free(ptr);
	}
	else if(n==2)
	{
		int pos,i;
		printf("enter the node number to be deleted\n");
		scanf("%d",&pos);
		for(i=0;i<pos-2;i++)
			ptr=ptr->next;
		temp=ptr->next;
		ptr->next=temp->next;
		free(temp);
	}
	else if(n==3)
	{
		int count=0,i;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			count++;
		}
		ptr=start;
		for(i=0;i<count-1;i++)
			ptr=ptr->next;
		ptr->next=NULL;
	}
}

void search()
{
	struct node *ptr;
	ptr=start;
	int data,f=0,count=0;
	printf("enter data to be searched\n");
	scanf("%d",&data);
    while(ptr!=NULL)
    {
    	if(ptr->info==data)
    	{
    		f=1;
    		break;
    	}
    	else
    	{
    		ptr=ptr->next;
    		count++;
    	}
    }
    if(f==1)
    	printf("element %d found at node %d",data,count+1);
    else
    	printf("element %d not found",data);
}

void display()
{
	int count=0,i;
	struct node *ptr;
	printf("List is\n");
	ptr=start;
	if(ptr==NULL)
		printf("List empty\n");
	do
	{
		printf("%d->",ptr->info);
		ptr=ptr->next;
	}while(ptr!=NULL);
	printf("NULL\n");
}
