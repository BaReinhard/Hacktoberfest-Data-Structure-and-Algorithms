/*				StackMain.c				*/
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

// Driver program 
int main(int argc, char **argv) 
{ 
    STACK *stack; 
  
    if (argc < 2)
    {
        printf ("Usage: %s <number>\n", argv[0]);
        exit (0);
    }

    stack = createStack (atoi (argv[1]));
    push(stack, 10); 
    push(stack, 20); 
    push(stack, 30); 
  
    printf("%d popped from stack\n", pop(stack)); 
  
    return 0; 
} 