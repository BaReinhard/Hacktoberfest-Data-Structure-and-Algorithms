package queues;

import java.util.Scanner;
class node
{
	Scanner s=new Scanner(System.in);
	int data;
	node next;
	node f;
	node r;
	node()
	{
		data=0;
		next=null;
		f=null;
	}
	public void enqueue()
	{
		System.out.println("ENTER THE DATA");
		int data=0;
		data=s.nextInt();
		node temp=new node();
		temp.data=data;
		if (f==null)
		{
			f=r=temp;
		}
		else
		{
			r.next=temp;
			r=r.next;
		}
	}
	public void display()
	{
		 if (f == null) { 
	          System.out.println("stack Underflow");   
	      } 
		  else
		  {
			  System.out.println("queue IS");
			  node temp=f;
			  while (temp!=null)
			  {
				  System.out.print(temp.data+" ");
				  temp=temp.next;
			  }
		  }
	}
	public void dequeue()
	{
		if (f == null) { 
	          System.out.println("stack Underflow");   
	      } 
		 else
		  {
			 node temp;
			 temp=f;
			 System.out.println("element which is dequeued"); 
			 System.out.println(temp.data);
			 f=f.next;
		
		  }
	}
}
public class queue_j {
	 public static void main(String[] args) 
	    { 

		 node a =new node();
		 int choice=0;
		 do
		 {
		 System.out.println("   ");
		 System.out.println("press 1 to enqueue"); 
		 System.out.println("press 2 to dequeue"); 
		 System.out.println("press 3 to display"); 
		 System.out.println("press 0 to exit"); 
		 Scanner s1=new Scanner(System.in);
		 choice=s1.nextInt();
		 switch(choice)
		 {
		 case 1:
			 a.enqueue();
			 break;
		 case 2:
			 a.dequeue();
			 break;
		 case 3:
			 a.display();
			 break;
		 default:
			 System.out.println("WRONG INPUT");
			 
		 }
		 }while(choice!=0 && choice<=3);
	    }
}
