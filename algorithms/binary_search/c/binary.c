/*Binary search program
You need to input only sorted numbers*/
#include<stdio.h>
//function defining
int bsearch(int key, int *a,int n)
{
	  int beg=0;
	  int end=n-1;
	  int mid=(beg+end)/2;
	while(beg<=end && a[mid]!=key){
	   if(key<a[mid])
	    {
	       end=mid-1;
	    }
	   else if(key>a[mid])
		 {
	            beg=mid+1;
		 }
 	mid=(beg+end)/2;
 	}
	if(beg>end)
	{	
	   return -1;//key not found
	}
return mid;//key found	
}//bsearch function ends here

int main()
{

//variables
	int i, key;
	int a[10];

//input
	printf("Enter 10 sorted elements\n");
	for(i=0;i<10;i++)
	{
           scanf("%d",&a[i]);
	}

//key
	printf("Enter number for searching\n");
	scanf("%d",&key);

//function calling
	i=bsearch(key,a,10);

//output
	if(i==-1)
	{
	   printf("Key not found\n");
	}
	else
	{
           printf("Key found at %d\n",i);
	}
	return 0;
}//main function ends here
