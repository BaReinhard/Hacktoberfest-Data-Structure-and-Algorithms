//Program to implement stack

#include <stdio.h>

#define SIZE 10

//integer structure
struct stack_int
{
	int top;
	int arr[SIZE];
	void (*push_int)(int, struct stack_int*);
	void (*display_int)(struct stack_int*);
	int (*pop_int)(struct stack_int*);

};

//character structure
struct stack_char
{
    int top;
    char arr[SIZE];
    void (*push_char)(char, struct stack_char*);
    char (*pop_char)(struct stack_char*);
	void (*display_char)(struct stack_char*);

};

//function to push into stack
void push_int(int, struct stack_int*);
void push_char(char, struct stack_char*);

//function to pop from stack
char pop_char(struct stack_char *);
int pop_int(struct stack_int *);

//function to display elements of stack
void display_int(struct stack_int *);
void display_char(struct stack_char*);

int main()
{
    //choice to select in menu and choice1 for integer or character stack
    int num, choice, choice1;
    char letter;

    //methods of stack_int and stack_char
    struct stack_int stk1;
    struct stack_char stk2;
    stk1.push_int = push_int;
    stk1.display_int= display_int;
    stk2.display_char=display_char;
    stk1.pop_int = pop_int;
    stk1.top =- 1;
    stk2.top = -1;
    stk2.push_char = push_char;
    stk2.pop_char = pop_char;

    x:
    printf("Do you want a Character Stack(0) or an Integer Stack(1):");
    scanf("%d", &choice1);
    if (choice1 != 0 && choice1 != 1)
    {
        printf("Invalid choice\n");
        goto x;
    }
    printf ("STACK OPERATION\n");
    while (1)
    {
        printf ("------------------------------------------\n");
        printf ("      1    PUSH               \n");
        printf ("      2    POP               \n");
        printf ("      3    DISPLAY               \n");
        printf ("      4    EXIT           \n");
        printf ("------------------------------------------\n");

        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                if (choice1 == 1)
                {
                    y:
                    printf("Enter a number to be pushed:");
                    scanf("%d", &num);
                    stk1.push_int(num, &stk1);
                }
                else
                {
                    printf("Enter a Character to be Pushed:");
                    scanf(" %c", &letter);
                    stk2.push_char(letter, &stk2);
                }
                break;

            case 2:
                if (choice1 == 1)
                    stk1.pop_int(&stk1);
                if (choice1 == 0)
                    stk2.pop_char(&stk2);
                break;

            case 3:
                if (choice1 == 1)
                    stk1.display_int(&stk1);
                else
                    stk2.display_char(&stk2);
                break;

            case 4:
                return 0;

            default:
                printf("Wrong choice, try again!\n");
        }
    }
}

//Function to push an element into the stack
void push_int(int num, struct stack_int *sta)
{
    if (sta->top == SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sta->top=sta->top + 1;
        sta->arr[sta->top] = num;
    }
}

//Function to display the contents in the Stack
void display_int(struct stack_int *sta)
{
    if (sta->top == -1)
    {
        printf("The Stack is Empty\n");
    }
    else
    {
         for (int i = sta->top; i > -1; i--)
         {
             printf("%d ", sta->arr[i]);
         }
	printf("\n");
    }
}

void display_char(struct stack_char *sta)
{
    if (sta->top == -1)
        printf("The Stack is Empty\n");
    else
    {
        for(int i = sta->top; i > -1; i--)
        {
            printf("%c ", sta->arr[i]);
        }
        printf("\n");
    }
}

//Function to pop the Top element of the Stack
int pop_int(struct stack_int *sta)
{
    if (sta->top == -1)
    {
        printf("The Stack is Empty Cant Pop anymore\n");
        return -1;
    }
    else
    {
        sta->top = sta->top - 1;
        printf("The popped element is %d\n", sta->arr[sta->top + 1]);
        return sta->arr[sta->top + 1];
    }
}

void push_char(char letter, struct stack_char *sta)
{
    if(sta->top == SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sta->top = sta->top + 1;
        sta->arr[sta->top] = letter;
    }
}

char pop_char(struct stack_char *sta)
{
    if (sta->top == -1)
    {
        printf("The Stack is Empty Cant Pop anymore\n");
        return 'f';
    }
    else
    {
        sta->top = sta->top - 1;
        printf("The Popped element is %c\n", sta->arr[sta->top + 1]);
        return sta->arr[sta->top + 1];
    }
}
