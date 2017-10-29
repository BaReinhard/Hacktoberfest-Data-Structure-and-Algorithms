#include<stdio.h>

int a1[1000000];

void merge(int a[], int l, int r, int mid)
{
	int i=l, j=mid+1, k=0;
	
	while(i<=mid && j<=r)
	{
		if(a[i]>a[j]) a1[k++]=a[j++];
		else a1[k++]=a[i++];
	}

	while(i<=mid)
	a1[k++]=a[i++];

	while(j<=r)
	a1[k++]=a[j++];

	for(i=0; i<k; i++)
	a[i+l]=a1[i];	
}

void msplit(int a[], int l, int r)
{
	if (l<r)
	{
		int mid=(l+r)/2;
		msplit(a,l,mid);
		msplit(a,mid+1,r);
		merge(a,l,r,mid);
	}
}

int main ()
{
	int n, a[100000], i;

	scanf("%d",&n);

	for(i=0; i<n; i++) scanf("%d",&a[i]);

	msplit(a,0,n-1);

	for(i=0; i<n; i++) printf("%d ",a[i]);

	printf("\n");

	return 0;
}
