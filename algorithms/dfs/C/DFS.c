#include<stdio.h>
int vis[10],count=0,v,a[10][10],n;
void dfs(int v)
{
	int i;
	vis[v]=1;
	for(i=1;i<=n;i++)
	{
		if((a[v][i]==1)&&(vis[i]==0))
		{
			printf("%d->%d\n",v,i);
			dfs(i);
		}
	}
}
int main()
{
	int i,j;
	printf("\nEnter the number of nodes");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		if(vis[i]==1)
		count++;
	}
	if(count==n)
	{
		printf("\nIt is a connected graph");
	}
	else
	{
		printf("\nIt is not a connected graph");
	}
}
	
