import java.util.*;
class Bubblesort{
public static void main(String args[])
{
	Scanner n = new Scanner(System.in);
	int temp;
	System.out.println("Enter the number of elements:");
	int no = n.nextInt();
	int a[]= new int[no];
	System.out.println("Enter the elements:");
	for(int i=0;i<no;i++)
		a[i]=n.nextInt();
	for(int i=0;i<no;i++)
	{
		for(int j=0;j<no-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp =a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	System.out.println("The sorted numbers are:");
	for(int i=0;i<no;i++)
	{
		System.out.println(a[i]+"\t");
	}
}
}