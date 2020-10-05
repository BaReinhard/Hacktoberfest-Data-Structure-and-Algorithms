import java.util.Scanner;

public class InsertionSortADT
{
	public static void main(String args[])
	{
		int a[]; // array reference

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size");
		int n = sc.nextInt();

		a = new int[n+1]; // dynamic memory allocation in java for array

		System.out.println("Enter the array elements");		
		for(int i=1;i<=n;i++)
		   a[i] = sc.nextInt();

		System.out.println("\n Before sorting...");
		display(a,n);
		
		insertionSort(a,n); // calling sorting function

		System.out.println("\n After sorting...");
		display(a,n);
	}

	public static void insertionSort(int a[], int n)
	{
		int i, j, temp;
		for(i=1;i<=n;i++)
		{
			temp = a[i];	
			j = i-1;	// j refers to previous positions
			while((j>0) && (temp < a[j]))
			{  
				a[j+1] = a[j]; // a[i-1+1] = a[i-1]
				j--;
			} // shifting is finished

			a[j+1] = temp; // Placing the temp back in the empty position
		}
	}

	public static void display(int a[],int n)
	{
		for(int i=1;i<=n;i++)
		 System.out.print(a[i]+"   ");
	}
}
