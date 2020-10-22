#include<stdlib.h>
#include<stdio.h>
#define size 50
int stack[size];
int top=-1;

void push(int val)
{
	if(top==size-1)
	{
		printf("Stack is full.");
	}
	else
	{
		top++;
		stack[top]=val;
	}
	
}
void pop()
{
	if(top==-1)
	{
		printf("Stack is empty.");	  
	}
	else
	{
		printf("Element removed=%d",stack[top]);
		top--;
	}
}


void peep()
{
	if(top==-1)
	{
		printf("Stack is empty.");	
	}
	else
	{
		printf("The element at the top is %d",stack[top]);
	}
}

void display()
{	int i;
	if(top==-1)
	{
		printf("Stack is empty.");	
	}
	else
	{	printf("The elements of stack are:\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\t",stack[i]);
		}
			
	}
}

int main()
{
	int choice,val;
	while(1)
	{
		printf("\n 1.Push\n 2.Pop\n 3.Peep\n 4.Display\n 5.Exit \nEnter your choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
					printf("ENter the Value:");
					scanf("%d",&val);
					push(val);
					break;
			case 2:
					pop();
					break;
			case 3:
					peep();
					break;
			case 4:
					display();
					break;
			case 5:
					exit(0);
			default:
					printf("Enter the correct choice.");
					
			
		
		}
		
	}
	


}

