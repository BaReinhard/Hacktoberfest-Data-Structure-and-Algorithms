/*Randomized Quick Sort*/
#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
	{
		int t=a;
		a=b;
		b=t;
	}
int partion(int arr[],int l,int u)
	{
		int down=l,up=u;
		int pivot=arr[l];
		while(down<up)
		{
			while(arr[down]<=pivot&&down<up)
				down++;
			while(arr[up]>=pivot&&up>=down)
				up--;
			if(down<up)
				swap(arr[down],arr[up]);
		}
		swap(arr[up],arr[l]);
		return up;
	}

int random(int arr[],int l,int u)
	{
		int pos=rand()%(u-l+1)+l;
		swap(arr[pos],arr[l]);
		int p=partion(arr,l,u);
		return p;

	}
void Quicksort(int arr[],int l,int u)
	{
		if(l<u)
		{
			int p=random(arr,l,u);
			Quicksort(arr,l,p-1);
			Quicksort(arr,p+1,u);
		}

	}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];
	int l=0,u=n-1;
	Quicksort(arr,l,u);
	cout<<"\n";

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	delete[] arr;
	return 0;
}