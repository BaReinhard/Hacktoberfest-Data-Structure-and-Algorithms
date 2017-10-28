#include<stdio.h>
#include<limits.h>

int heap[100005];
int r = 0;

void swap(int i,int j)
{
	heap[i] = heap[i] + heap[j] - (heap[j]=heap[i]);
}

void heapify(int tmp)
{
	if(tmp==1)
		return ;

	if(heap[tmp] < heap[tmp/2])
	{
		swap(tmp/2,tmp);
		return heapify(tmp/2);
	}

	return;
}

void printheap(int tmp)
{
	if(tmp>r)
		return;
	printheap(2*tmp);
	printf("%d ",heap[tmp]);
	printheap(2*tmp+1);
	return;
}

int min(int a, int b, int c)
{
	if(a<=b && a<=c)
		return a;
	if(b<=c)
		return b;
	return c ;
}

void delete(int pos)
{
	if(pos>r/2)
		return;
	int tmp = min(heap[pos],heap[2*pos],heap[2*pos+1]);

	if(heap[pos]==tmp)
		return ;
	if(tmp=heap[2*pos])
	{
		swap(pos,2*pos);
		return delete(2*pos);
	}

	swap(pos,2*pos+1);
	return delete(2*pos+1);
}

int findpos(int value)
{
	int i;
	for(i=1;i<=r;i++)
		if(heap[i]==value)
			return i;
	return 0;
}

int main()
{
	r = 0;
	int i;
	for(i=0;i<100005;i++)
		heap[i]=INT_MAX ;

	int q;
	scanf("%d",&q);
	while(q--)
	{
		int fn;
		scanf("%d",&fn);

		if(fn==1)
		{
			int value ;
			scanf("%d",&value);
			heap[++r]=value;
			heapify(r);
		}

		if(fn==2)
		{
			int value;
			scanf("%d",&value);
			int pos = findpos(value);
			if(pos<=r)
			{
				swap(pos,r);
				heap[r]=INT_MAX;
				r--;
				delete(pos);
			}

			else
				printf("Value does not exist\n");
		}

		if(fn==3)
			printf("%d\n",heap[1]);

	/*	printf("r : %d\n",r);

		for(i=1;i<=r;i++)
			printf("%d ",heap[i]);
		printf("\n");
		printheap(1);
		printf("\n");*/
	}

	return 0;
}

