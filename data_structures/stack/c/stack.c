#include<stdio.h>
#define MAX_SIZE 10
//Stack max size is 10. After that overflow will occour.

void display();
void push(int);
void pop();

int stack[MAX_SIZE];
int top=-1;

void main()
{
	//valaue variable used to store elements in stack
	//choice variable is used to decide what function to use
	int value,choice;
	
	while(1)
 {
	printf("***************************\n");
	printf("1.push\n2.pop\n3.display\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	//Here We Are Using Switch Case For Push , Pop & Display Function
		switch(choice)
	 {
		case 1:printf("enter the value to be push into stack\n ");
		scanf("%d",&value);	
		push(value);
		break ;
		case 2:pop();
		 break;
		case 3:display();
		 break;
		default:printf("wrong input please try again\n");
	  }//end of switch
 }//end of while
}//end of main

void display(){
	if(top==-1)
	{	
	  	printf("Stack is empty\n\n");	
	}
	else
	{ 		 
 		 printf("\nstack contains %d elements\n",top+1); 	
	}
	int i=0;
	for(i=top;i>=0;i--)
	{
	 printf("%d\n",stack[i]);
	}
}

void push(int value)
{
	if(top==MAX_SIZE-1)
	{
             printf("\nOverflow\n\n");   
	}
	else
	{
		//this statement will add wlwmwnts in stack
	     	top=top+1;
		//this statement will declared latest value which was inputed in stack as Top
		stack[top]=value;
	}
}

void pop()
{
	if(top==-1)
	{
           printf("\nUnderflow\n\n");
		//If there is no element in stack & you tried pop then Underflow will occour.
	}
	else
	{
		//This will pop elements from stack
		top=top-1;
		
	}
}

