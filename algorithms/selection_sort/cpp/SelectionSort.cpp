#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n)
{
	int min_idx, temp;

	for (int i = 0; i < n - 1; i++)
	{
	    min_idx = i;
		
		for (int j = i + 1; j < n; j++)
		{

		if (arr[j] < arr[min_idx])			
        	min_idx = j;
		}
		
		// swap if min position has changed
	    if (min_idx != i)
        {
             temp = arr[i];
             arr[i] = arr[min_idx];
             arr[min_idx] = temp;
        }
	}
}

int main() {
    
    // Testing array
    int i, size = 10;
    int arr [size] = {12, 33, 1, 3, 54, 32, 78, 54, 99, 6}; 
    
    // Print result
    printf("Tested array: \n");
    for(i = 0; i < size; i++)
		printf("%d ", arr[i]);
	
	// Sort array
    SelectionSort(arr, size);
    
	printf("\nSorted array:\n");
	for(i = 0; i < size; i++)
		printf("%d ", arr[i]);
		
	return 0;
}