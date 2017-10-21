#include<stdio.h>

//function declarations
void merge(int *a,int beg, int end);
void mergeArray(int *a, int lbeg, int lend, int rbeg, int rend);

int main()
{
//variables
	int i;
	int a[10];
//input
	printf("Enter numbers\n");
	for(i=0;i<10;i++)
	{
	  scanf("%d",&a[i]);
	}
//function calling
	merge(a, 0, 10-1);

//output
	printf("Numbers sorted\n");
	for(i=0;i<10;i++)
	{
	  printf("%d\n",a[i]);
	}
	return 0;
}

//merge function
void merge (int *a,int beg,int end)
{
	int mid;	
	if(beg<end)
	  {
            mid=(beg+end)/2;//finding mid
	    merge(a, beg, mid);
	    merge(a, mid+1, end);	
	    mergeArray(a,beg, mid, mid+1,end);	
          }
}//merge sort ends here

void mergeArray(int *a, int lbeg, int lend, int rbeg, int rend){
	
	int pa=lbeg, pb=rbeg,pt=lbeg, temp[10];
//for reducing confusion we have used pa, pt for lbeg
	while(pa<=lend && pb<=rend)
		{
         	 if(a[pa]< a[pb])
	              {
	                 temp[pt++]=a[pa++];
	               }
	        else
	          {
	                temp[pt++]=a[pb++];
	          }
	        }
	if(pa>lend)
	{
//left array exhausted
	  while(pb<=rend)
	      {
	         temp[pt++]=a[pb++];
	      }
	}
	else
	{
//right array get exhausted
	   while(pa<=lend)
	       {
	         temp[pt++]=a[pa++];
	       }
	}
//write sorted elements in array

	for(pt=lbeg;pt<=rend;pt++)
	 {
	    a[pt]=temp[pt];
	 }
}//merge Array function ends here
