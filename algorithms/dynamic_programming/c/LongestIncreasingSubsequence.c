// length of lis
#include <stdio.h>
int lis (int a[], int n)
{
	int ans[1005]={0};
	for (int i=0; i<n; i++)
		ans[i]=1;
	for (int i=1; i<n; i++)
	{
		for (int j=0; j<i; j++)
		{
			if (a[i]>a[j])
			{
				if (ans[i] < ans[j] + 1)
					ans[i] = ans[j] + 1;
			}
		}
	}
	int i;
	for (i=0; i<n-1; i++)
	{
		if (ans[i]>ans[i+1])
		{
			int temp=ans[i];
			ans[i]=ans[i+1];
			ans[i+1]=temp;
		}
	}
	return ans[n-1];
}

int main () 
{
	int t, n, a[1005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for (int i=0; i<n; i++)
			scanf("%d",&a[i]);
		printf("%d\n",lis(a, n));
	}
	return 0;
}
