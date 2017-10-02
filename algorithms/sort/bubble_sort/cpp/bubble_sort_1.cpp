#include<iostream>
using namespace std;

//global variables for ease of use
long long int array[1000],n,temp;

//function for bubble sort
void bubble_sort()
{

	for(register long long int i=0;i<n;i++)
	{
		for(register long long int j=0;j<n-i-1;j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}	
	}
}
int main()
{
	// Enter the number of elements 
	cin>>n;

	//Entering the elements
	for(register long long int i=0;i<n;i++)
	{
		cin>>array[i];
	}

	//buuble sort
	bubble_sort();

	//Sorted order
	for(register long long int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
}
