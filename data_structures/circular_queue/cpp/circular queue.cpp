#include<iostream>
#include<conio.h>
using namespace std;

class queue1
{

    int n=8,front1=-1,rear=-1,a=0;
public:

    int arr[8];

    void element()
    {

        cout<<"enter element";
        cin>>a;
    }
    void inqueue()
    {
    if((front1>=0&&rear==n-1)||(front1==rear+1))
            {
             //overflow
             cout<<"queue overflow"<<endl;
            }
   if (front1==-1&&rear==-1)
        {
            //queue empty
            front1=0;
            rear=0;
            arr[rear]=a;

        }
        else if(rear==n-1)
            {
                rear=0;
                arr[rear]=a;

            }

        else {
                rear++;
               arr[rear]=a;
            }
    }
    int b;
    void dequeue()
    {
        if(rear==-1&&front1==-1)
        {
            cout<<"underflow"<<endl;
        }
    if (front1==rear)
        {
            //one element
            b=arr[front1];
            cout<<"deleted single element is :"<<b<<endl;
            front1=-1;
            rear=-1;

        }
        else if (front1==n-1)
        {
            b=arr[front1];
            cout<<"deleted element last is :"<<b<<endl;
            front1=0;
        }
        else
        {
           b=arr[front1];
            cout<<"deleted any element is :"<<b<<endl;
            front1++;
        }

    }
    void display()
    {
        cout<<"the no. in queue are"<<endl;
        for(int i=front1;i<=rear;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
};
    int main()
    {
        queue1 q;
        int ch,c=1;

while(c==1)
{
        cout<<"enter choice 1.insertion 2.deletion 3.display 4.exit"<<endl;
        cin>>ch;
   switch(ch)
{
    case 1:
        {
            q.element();
            q.inqueue();
            break;
        }
    case 2:
        {
            q.dequeue();
            break;
        }
    case 3:
        {
            q.display();
            break;
        }
    case 4:
        {
            c=0;
            break;
        }
}
}
}


//seraching n traversing in lkd list
