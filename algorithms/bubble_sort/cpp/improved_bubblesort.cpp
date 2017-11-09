#include <bits/stdc++.h>
using namespace std;


void bubble_sort_improved(int arr[],int n)
{	
	bool sorted = true;
	for(int i=0;i<n-1;i++)
	{	
		
		if(i%2==0){

			sorted = true;
			for(int j=i/2;j<n-1-i/2;j++)
				if(arr[j]>arr[j+1])
					{
						sorted = false;
						swap(arr[j],arr[j+1]);
					}
			if(sorted)
				break;
		}
		else{

			sorted = true;
			for(int j=n-1-i/2;j>i/2;j--)
				if(arr[j]<arr[j-1])
					{
						sorted = false;
						swap(arr[j],arr[j-1]);
					}
			if(sorted)
				break;

		}

	}
}



int main(){

	int n;
	cin>>n;
	
	
	int *arr1 = new int [n];
	
	int t;

	for (int i = 0; i < n; ++i)
		{
			cin>>t;
			arr1[i]=t;
		}

	bubble_sort_improved(arr1,n);	
	
	for(int i=0;i<n;i++)
		cout<<arr1[i]<<" ";
	
	delete [] arr1;

	
	return 0;
}