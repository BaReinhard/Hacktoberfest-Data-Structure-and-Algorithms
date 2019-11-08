#include <stdio.h>
#include <stdlib.h>

// Data structure for stack
struct stack
{
	int maxsize;	// define max capacity of stack
	int top;		
	int *items;
};

// Utility function to initialize stack
struct stack* newStack(int capacity)
{
	struct stack *pt = (struct stack*)malloc(sizeof(struct stack));

	pt->maxsize = capacity;
	pt->top = -1;
	pt->items = (int*)malloc(sizeof(int) * capacity);

	return pt;
}

// Utility function to return the size of the stack
int size(struct stack *pt)
{
	return pt->top + 1;
}

// Utility function to check if the stack is empty or not
int isEmpty(struct stack *pt)
{
	return pt->top == -1;	// or return size(pt) == 0;
}

// Utility function to check if the stack is full or not
int isFull(struct stack *pt)
{
	return pt->top == pt->maxsize - 1;	// or return size(pt) == pt->maxsize;
}

// Utility function to add an element x in the stack
void push(struct stack *pt, int x)
{
	// check if stack is already full. Then inserting an element would 
	// lead to stack overflow
	if (isFull(pt))
	{
		printf("OverFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}

	printf("Inserting %d\n", x);
	pt->items[++pt->top] = x;
}

// Utility function to return top element in a stack
int peek(struct stack *pt)
{
	// check for empty stack
	if (!isEmpty(pt))
		return pt->items[pt->top];
	else
		exit(EXIT_FAILURE);
}

// Utility function to pop top element from the stack
int pop(struct stack *pt)
{
	// check for stack underflow
	if (isEmpty(pt))
	{
		printf("UnderFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}

	printf("Removing %d\n", peek(pt));

	// decrease stack size by 1 and (optionally) return the popped element
	return pt->items[pt->top--];
}

// main function
int main()
{
	// create a stack of capacity 5
	struct stack *pt = newStack(5);

	push(pt, 1);
	push(pt, 2);
	push(pt, 3);
	push(pt, 4);
	push(pt, 5);

	printf("Top element is %d\n", peek(pt));
	printf("Stack size is %d\n", size(pt));

	pop(pt);
	pop(pt);
	pop(pt);

	if (isEmpty(pt))
		printf("Stack is empty");
	else
		printf("Stack is not empty");

	return 0;
}
