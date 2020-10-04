#include <stdio.h>
#include <conio.h>
# define max 5

int queue[max];
int f = -1, r = -1;
int count = 0;

void enqueue();
void dequeue();
void display();

void main()
{
    int n;
    clrscr();
    do
    {
        printf("\nEnter choice:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
        }
    }while(n != 4);
    getch;
}

void enqueue()
{
    int data;
    if(r == max-1)
    {
        printf("This is the condition of overflow. Enqueue operation is not possible");
    }
    else
    {
        printf("Enter the new data");
        scanf("%d", &data);
        if((f == -1) && (r == -1))
        {
            f = 0;  //f++;
            r = 0;  //r++;
            queue[f] = data:
        }
        else
        {
            r = r+1;    //r++;
            queue[r] = data;
        }
        count++;
    }
}

void dequeue()
{
    if((f == -1) || (r == -1))
    {
        printf("This is the condition of underflow. Dequeue operation is not possible.");
    }
    else
    {
        if(f == r)
        {
            printf("%d is the last element in the queue and is being dequeued.", queue[r]);
            f = -1;
            r = -1;
        }
        else
        {
            printf("%d is dequeued.", queue[f]);
            f++;
        }
        count--;
    }
}

void display()
{
    if((f == -1) || (r == -1))
    {
        printf("This is the condition of underflow. Nothing to display in the queue.");
    }
    else
    {
        printf("Elements present in the queue are:\n");
        for(i = f; i <= r; i++)
        {
           printf("%d\t", queue[i]);
        }
    }
}
