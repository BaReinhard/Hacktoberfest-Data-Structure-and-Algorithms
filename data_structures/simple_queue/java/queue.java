import java.util.*;
interface queue
{
	void insert();
	void delete();
	void display();
	
}
class myqueue implements queue
{
	int arr[]=new int[10];
	int front=0,rear=0;
	Scanner s1 = new Scanner(System.in);
	public void insert()
	{
		if (rear>10)
			System.out.println("queue overflow");
		else
		{
			int a;
			System.out.println("enter element:");
			a=s1.nextInt();
			arr[rear]=a;
			rear++;
		}
	}
public void delete()
	{
		if (rear==front)
			System.out.println("queue is empty");
		else
		{
			int a;
			a=arr[front];
			front++;
			System.out.println("element deleted : "+a );
		}
	}
	public void display()
	{
		System.out.println("elements are");
		for(int i=front;i<rear;i++)
		{
			System.out.println(arr[i]);
		}
	}
}
class tut6
{
public static void main(String args[])
{
	Scanner s = new Scanner(System.in);
		myqueue m = new myqueue();
		boolean b= true;
		while(b)
		{
		System.out.println("enter ur choices \n 1. push \n 2. pop \n 3. display \n 4. exit");
		int n;
		n=s.nextInt();
		
		
		switch(n)
		{
		case 1:
		m.insert();
		break;
		case 2:
		m.delete();
		break;
		case 3:
		m.display();
		break;
		case 4:
		System.exit(0);
		}
		}
	}
}

