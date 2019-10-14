 #include <stdio.h>
#include <stdlib.h>

int a[10];
int b[10];

void merge_sort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid = ((low+high)/2) ;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge_it(low,mid,high);
    }
}

void merge_it(int low,int mid, int high)
{
    int h,i,j,k;
    h = low;
    i = low;
    j = mid +1;

    while(h<=mid && j<=high)
    {
        if(a[h]<=a[j])
        {
            b[i] = a[h];
            h++;
        }
    else{
        b[i] = a[j];
        j++;
    }
    i++;
    }

    if(h>mid)
    {
        for(k=j;k<=high;k++)
        {
            b[i] = a[k];
            i++;
        }
    }
   else{
    for(k=h;k<=mid;k++)
    {
        b[i] = a[k];
        i++;
    }
   }

    for(k=low;k<=high;k++)
    {
        a[k] = b[k];
          }
}


int main()
{
    int low = 0;
    int high,i,n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter %d element: ",i+1);
        scanf("%d",&a[i]);
    }

    high = n-1;

    merge_sort(low,high);
    for(i=0;i<n;i++)
    printf(" %d ",a[i]);


    return 0;
}
