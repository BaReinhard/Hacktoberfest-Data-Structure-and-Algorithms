#include<stdio.h>
#include<stdlib.h>
struct MinHeap
{
    int size;
    int* array;
};
void swap(int* a, int* b) 
 { 
 	int swp = *a;
 	*a = *b;
 	*b = swp; 
 }
void minHeapify(struct MinHeap* minHeap, int p)
{
    int smallest = p;  
    int left = (p << 1) + 1;  
    int right = (p + 1) << 1; 
    if (left < minHeap->size && 
        minHeap->array[left] < minHeap->array[smallest])
        smallest = left;
 	if (right < minHeap->size && 
        minHeap->array[right] < minHeap->array[smallest])
        smallest = right;
    if (smallest != p)
    {
        swap(&minHeap->array[smallest], &minHeap->array[p]);
        minHeapify(minHeap, smallest);
    }
}

struct MinHeap* BuildHeap(int *ar, int size)
{
    int i;
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = size;  
    minHeap->array = ar; 
    for (i = (minHeap->size - 2) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
    return minHeap;
}
void heapSort(int* ar, int size)
{
    struct MinHeap* minHeap = BuildHeap(ar, size);
 	while (minHeap->size > 1)
    {
        swap(&minHeap->array[0], &minHeap->array[minHeap->size - 1]);
        --minHeap->size; 
        minHeapify(minHeap, 0);
    }
}
void print(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
    int size = sizeof(arr)/sizeof(arr[0]);
 
    /*printf("Given array is \n");
    print(arr, size);*/
 
    heapSort(arr, size);
 
    //printf("\nSorted array is \n");
    print(arr, size);
    printf("\n");
    return 0;
}





struct MinHeap
{
    int size;
    int* array;
};
void swap(int* a, int* b) 
 { 
    int swp = *a;
    *a = *b;
    *b = swp; 
 }
void minHeapify(struct MinHeap* minHeap, int p)
{
    int smallest = p;  
    int left = (p << 1) + 1;  
    int right = (p + 1) << 1; 
    if (left < minHeap->size && 
        minHeap->array[left] < minHeap->array[smallest])
        smallest = left;
    if (right < minHeap->size && 
        minHeap->array[right] < minHeap->array[smallest])
        smallest = right;
    if (smallest != p)
    {
        swap(&minHeap->array[smallest], &minHeap->array[p]);
        minHeapify(minHeap, smallest);
    }
}

struct MinHeap* BuildHeap(int *ar, int size)
{
    int i;
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = size;  
    minHeap->array = ar; 
    for (i = (minHeap->size - 2) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
    return minHeap;
}
void heapSort(int* ar, int size)
{
    struct MinHeap* minHeap = BuildHeap(ar, size);
    while (minHeap->size > 1)
    {
        swap(&minHeap->array[0], &minHeap->array[minHeap->size - 1]);
        --minHeap->size; 
        minHeapify(minHeap, 0);
    }
}
void print(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}
