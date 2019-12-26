#include<stdio.h>
//Complexity of this program is also O(n^2).
void select(int *a, int n)
{
	int k,j,temp,small,pos;
	for(k=1;k<=n-1;k++)
	{
	small=a[k-1];
	pos=k-1;
	for(j=k;j<=n-1;j++)
	{
	if(a[j]<small)
	{
	  small=a[j];
	  pos=j;
	}
	}
	if(pos!=k-1)
	{
	   temp=a[k-1];
	   a[k-1]=a[pos];
	   a[pos]=temp;
	}
	}
}//select function ends here

int main()
{
	int i;
	int a[10];
//input 
	printf("Enter Numbers\n");
	for(i=0;i<10;i++)
	{
	  scanf("%d",&a[i]);
	}
//function calling
	select(a,10);

//output
	printf("Sorting Complete\n");
	for(i=0;i<10;i++)
	{
	  printf("%d\n",a[i]);
	}
	return 0;
}
