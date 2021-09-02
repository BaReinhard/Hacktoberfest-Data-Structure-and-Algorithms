#include<iostream>
using namespace std;

struct node
{
	int l, r;
	node *next;
};

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int array[],int l, int r)
{
	int part = l,i;
	for(i=l;i<=r;i++)
	{
		
		if(array[i]<array[r])
		{
			swap(array[i],array[part]);
			part++;
		}

	}
	swap(array[part],array[r]);
	return part;
}

void quicksort(int array[],int n)
{
	node *stack = new node,*ptr,*ptr2;
	stack->l = 0;
	stack->r = n-1;
	stack->next = NULL;

	while(stack!=NULL)
	{
		ptr = stack;
		stack = stack->next;
		int part = partition(array,ptr->l,ptr->r);
		if(part-ptr->l>1)
		{
			ptr2 = new node;
			ptr2->l = ptr->l;
			ptr2->r = part-1;
			ptr2->next = stack;
			stack = ptr2;
		}
		if(ptr->r-part>1)
		{
			ptr2 = new node;
			ptr2->l = part+1;
			ptr2->r = ptr->r;
			ptr2->next = stack;
			stack = ptr2;
		}	

	}

}



int main()
{
	int n,i;
	cout<<"How many numbers : ";
	cin>>n;
	int *a = new int[n];
	for(int i = 0;i<n;i++)
		cin>>a[i];

	quicksort(a,n);

	cout<<"Sorted ans. is : ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}

	return 0;
}
