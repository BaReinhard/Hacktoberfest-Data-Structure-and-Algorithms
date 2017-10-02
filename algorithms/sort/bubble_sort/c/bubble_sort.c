//algorithm of bubble sort in c
//start from the first elemnent 
/*1. start comparing it with the next element
  2. swap the element with the first smaller element it encounters.
  3. every traversal pushes the largest element towards the end.
*/
  



void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

int main()
{
int i,j,k;
int a[5];
for(i=0;i<5;i++)
scanf("%d",&a[i]);
bubblesort(a,5);
for(i=0;i<5;i++)
printf("%d\n",a[i]);

return 0;
}
