
void main()
{
	int m,n,i,j,a[10][10],t[10][10];
	printf("Enter m and n:\t");
	scanf("%d%d",&n,&m);
	printf("\nEnter elements\t");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	//printing the matrix
	printf("The matrix is\t\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	//finding transpose
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			t[j][i]=a[i][j];
		}
	}
	//printing transpose
	printf("The matrix is\t\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d\t",t[i][j]);
		}
		printf("\n");
	}
}
