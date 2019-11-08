/*				Stack.h					*/
 
// A structure to represent a stack 
typedef struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
} STACK; 
  
STACK* createStack(unsigned );
// Stack is full when top is equal to the last index 
int isFull(STACK* );
// Stack is empty when top is equal to -1 
int isEmpty(STACK* );
// Function to add an item to stack.  It increases top by 1 
void push(STACK* , int);
// Function to remove an item from stack.  It decreases top by 1 
int pop(STACK*);
// Function to return the top from stack without removing it 
int peek(STACK *);