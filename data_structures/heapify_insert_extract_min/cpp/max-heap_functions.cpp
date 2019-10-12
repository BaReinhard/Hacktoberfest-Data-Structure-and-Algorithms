#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    void heapify(int k,int arr[]);
    void insert(int t,int arr[]);
    int extract_max(int arr[]);

    int n;
    int size;
    int flag;
    int max;
    int temp;
    int temp1;
    int xx;
    int h;

    int main()
    {
        int N;
        int i,T;
        int query;
        int j;

        scanf("%d",&N);

        int array[N];
        int array1[N];

        size=N;
        int element;

        for(i=0;i<N;i++)
        {
            scanf("%d",&array[i]);
        }

        scanf("%d",&T);
 	
	// create a sorted heap

        for(j=0;j<N;j++)
        {
            heapify(j,array);
        }
// for using various functions
        for(i=0;i<T;i++)
        {
            scanf("%d",&query);
            switch(query)
            {
                // pirnt the max-heap 
                case 0:
                    for(j=0;j<size;j++)
                    {
                        heapify(j,array);
                    }
                    for(j=0;j<size;j++)
                    {
                        printf("%d ",array[j]);
                    }
                    printf("\n");
                    break;
                // heapsort and then print the sorted array
                case 1:
                    xx=size;
                    for(j=0;j<xx;j++)
                    {
                        array1[j]=array[j];
                    }
                    for(j=0;j<xx;j++)
                    {
                        extract_max(array1);
                    }
                    for(h=0;h<xx;h++)
                    {
                        printf("%d ",array1[h]);
                    }
                    printf("\n");
                    size=xx;
                    break;
                // insert element into max-heap, then print the heap
                case 2:
                    scanf("%d",&element);
                    insert(element,array);
                    for(h=0;h<size;h++)
                    {
                        printf("%d ",array[h]);
                    }
                    printf("\n");

                    break;
                // extract maximum element in the max heap and then print the max-heap
                case 3:
                    extract_max(array);
                    for(j=0;j<size;j++)
                    {
                        printf("%d ",array[j]);
                    }
                    printf("\n");
                    break;
                // print maximum element of the max-heap
                case 4:
                    printf("%d\n",array[0]);
                    break;

            }
        }



        return 0;
    }

    void heapify(int k,int arr[])
    {
        n=size-1;
        flag=1;
        //printf("n: %d \n",n);
        //printf("parent: %d\n",(int)floor((double)(n-1)/2.0));
        while(k<=(int)floor((double)(n-1)/2.0) && flag==1)
        {
            max=k;
            if(arr[k]<arr[2*k+1])
            {
                max=2*k+1;
            }
            if(2*k+2<=n && arr[max]<arr[2*k+2])
            {
                max=2*k+2;
            }
            if(max!=k)
            {
                temp1=arr[k];
                arr[k]=arr[max];
                arr[max]=temp1;
                k=max;
            }
            else
            {
                flag=0;
            }
        }
    }

    void insert(int t,int arr[])
    {
        n=size;
        //printf("t %d",t);
        arr[size]=t;
        size+=1;
        while(n>0 && arr[n]>arr[(int)floor((double)(n-1)/2.0)])
        {
            temp=arr[n];
            arr[n]=arr[(int)floor((double)(n-1)/2.0)];
            arr[(int)floor((double)(n-1)/2.0)]=temp;
            n=(int)floor((double)(n-1)/2.0);
        }
    }

    int extract_max(int arr[])
    {
        n=size-1;
        temp=arr[0];
        arr[0]=arr[n];
        arr[n]=temp;
        //printf("arr[0],arr[n]:- %d %d\n",arr[0],arr[n]);
        size-=1;
        //printf("%d",size);
        heapify(0,arr);
        return temp;
    }
