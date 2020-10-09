#include<stdio.h>
#include<stdlib.h>

void binarySearch(int searchValue, int a[], int n);

void selectionSort(int a[], int n)
{
    int i, j, minimunIndex, temp;

    printf("Just started to sort Using the Selection Sort Algorithm\n");

    for ( i = 0; i < n; i++)
    {
        minimunIndex = i;

        for ( j = i + 1; j < n; j++)
        {
            if (a[minimunIndex] > a[j])
                minimunIndex = j;    
        }
        temp = a[i];
        a[i] = a[minimunIndex];
        a[minimunIndex] = temp;
    }

    printf("Ended Sorting using Selection Sort\n");
}


void main()
{
    int length, i, searchValue;
    printf("Welcome to the Binary Search!!\n");
    printf("You can search the data element from an array, don't worry I will do it for you\n");
    printf("For simplicity here the data elements are considered as integers\n");
    printf("So let me know how many integers you want:\n");
    scanf("%d", &length);

    int *a = (int *) calloc (length, sizeof(int));

    printf("Please enter the integers now:\n");
    for ( i = 0; i < length; i++)
    {
        scanf("%d", &a[i]);
    }
    
    printf("Please enter the value you want me to search for:\n");
    scanf("%d", &searchValue);

    // Binary Search needs the sorted array as input without which the search can't occur
    // Hence sorting elements before the Search
    selectionSort(a, length);

    binarySearch(searchValue, a, length);

    printf("Thanks for Investing time in Me!!");
}

void binarySearch(int searchValue, int a[], int n)
{
    int middle, first, last;
    first = 0;
    last = n-1;

    middle = first + last / 2;

    printf("Starting to search the Data element --> %4d\n", searchValue);   
    while( first <= last)
    {
        if(a[middle] < searchValue)
            first = middle + 1;

        else if(a[middle] == searchValue)
        {
            printf("The element %d was found at the location %d starting from 0\n", searchValue, middle);
            break;
        }
        else
            last = middle - 1;
        
        middle = first + last / 2; 
    }

    if (first > last)
    {
        printf("Sorry the element you wanted me to Search doesn't exist in the given array\n");
    }

    printf("Just Ended Binary Search\n");
}