#include <stdio.h>
#include <stdlib.h>
# define max 5
int queue[max];
int f=0,r=-1;
int count=0;
int main()
{
    int n;
    do
    {
        printf("\nEnter choice:\n1.Push\n2.POP\n3.Display\n4.Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            break;
        }
    }while(n!=4);
    return 0;
}

void push()
{
    int data;
    printf("\n");
    if((f==0 && r==max-1) || (f>0 && r==f-1))
        printf("queue overflow\n");
    else if((r==-1 && f==0) || (f==0 && r<max-1) || (f>0 && r!=f))
    {
        r=(r+1)%max;
        printf("Enter element\n");
        scanf("%d",&queue[r]);
        count++;
    }
    printf("\n\n");
}

void pop()
{
    if(r==-1 || (f>0 && f==(r+1)%max))
        printf("\nUnderflow\n");
    else
    {
        printf("\nElement %d is popped out\n",queue[f]);
        f=(f+1)%max;
        count--;
    } printf("\n\n");
}

void display()
{
    printf("\n");
    int i;
    printf("\nElements present are\n");
    for(i=0;i<count;i++)
    {
        printf("%d\t",queue[f]);
        f=(f+1)%max;
    }
    printf("\n\n");
}