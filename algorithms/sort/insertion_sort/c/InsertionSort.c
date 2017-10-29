// C program for insertion sort
#include <stdio.h> 
/* Function to sort an array using insertion sort */
void insertionSort(int ar[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = ar[i];
       j = i-1;
       /* Move elements with indices from 0 to i-1 that are greater 
       than key, to one position ahead of their current position */
       while (j >= 0 && ar[j] > key)
       {
           ar[j+1] = ar[j];
           j = j-1;
       }
       ar[j+1] = key;
   }
}
// method to print array
void print(int ar[], int n)
{
   for (int  i=0; i < n; i++){
       printf("%d ", ar[i]);
   }
}
/* To test insertion sort function */
int main()
{
    int arr[] = {10, 29, 1, 9, 37, 24, 6, 3, 11};
    // Calculates array size
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    print(arr, n);
    return 0;
}
