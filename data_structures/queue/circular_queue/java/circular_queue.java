//circular queue
import java.util.*;
interface queue1
{
	void insert();
	void delete();
	void display();
	
}
class myqueue1 implements queue1
{
	int arr[]=new int[3];
	int front=0,rear=0;
	Scanner s1 = new Scanner(System.in);
	public void insert()
	{
			int a;
			System.out.println("enter element:");
			a=s1.nextInt();
			arr[rear]=a;
			rear++;
		if(rear==3)
			rear=0;
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
			if(front==3)
			front=0;
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
class tut7
{
public static void main(String args[])
{
	Scanner s = new Scanner(System.in);
		myqueue1 m = new myqueue1();
		boolean b= true;
		while(b)
		{
		System.out.println("enter ur choices \n 1. insert \n 2. delete \n 3. display \n 4. exit");
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
