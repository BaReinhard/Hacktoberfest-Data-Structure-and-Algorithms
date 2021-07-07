#include<stdio.h>
#include<stdlib.h>

int radix_sort(int a[],int b[],int n,int m)
{
	int i,j=0,output[100],temp[100],l=1;
	while(l!=n)
	{
		for(i=0;i<=10;i++)
			b[i]=0;
		for(i=0;i<m;i++)
		{
			temp[i]=(a[i]/l)%10;
			b[temp[i]]++;

		}
		for(i=1;i<=10;i++)
			b[i]=b[i-1]+b[i];
		for(i=m-1;i>=0;i--)
			output[--b[temp[i]]]=a[i];
		for(i=0;i<m;i++)
			a[i]=output[i];
		l=l*10;
	}
}

void main()
{
	int a[100],b[100];
	int i,m,n;
	printf("Input upper range:");
	scanf("%d",&n);
	printf("Input number of numbers:");
	scanf("%d",&m);
	printf("Input numbers between 0 and %d:",n);
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	radix_sort(a,b,n,m);
	for(i=0;i<m;i++)
		printf("%d ",a[i]);
}
