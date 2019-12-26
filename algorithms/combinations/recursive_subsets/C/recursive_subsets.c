//this algorithm prints all subsets of a set (except for the empty set):

#include <stdio.h>

void combine(int array[], int temp[], int start, int end, int index, int s, int *counter)
{
    if (index == s) //prints.
    {
        for (int j=0; j<s; j++)
            printf("%d ", temp[j]);
            ++*counter;
        printf("\n");
        return;
    }
 
    for (int i=start; i<=end && end-i+1 >= s-index; i++)
    {
        temp[index] = array[i];
        combine(array, temp, i+1, end, index+1, s, counter);
    }
}

int main()
{
    int s, n, counter = 0;
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // you can change your set here.
    int temp[s];

    n = sizeof(array)/sizeof(array[0]);

    for (s=1; s<=n; s++) combine(array, temp, 0, n-1, 0, s, &counter);
    
    printf("\nTotal: %d\n", counter);
}
