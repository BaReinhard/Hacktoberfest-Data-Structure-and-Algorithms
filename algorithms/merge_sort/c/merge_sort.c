#ifndef MERGE_SORT_C
#define MERGE_SORT_C 1

void merge(int A[], int low, int mid, int high)
{
	int tmpStorage[high-low+1];
	for(int k = low; k <= high; ++k)
	{
		tmpStorage[k] = A[k];
	}
	int i = low; j = mid+1, k = low;
	while(i <= mid && j <= high)
	{
		if(tmpStorage[i] < tmpStorage[j])
		{
			A[k++] = tmpStorage[i++];
		}
		else
		{
			A[k++] = tmpStorage[j++];
		}
	}
	if(i <= mid)
	{
		j = i;
	}
	while(k <= high)
	{
		A[k++] = tmpStorage[j++];
	}
}

void mergeSort(int A[], int low, int high)
{
	if(low < high)
	{
		int mid = (low+high)/2;
		mergeSort(A, low, mid);
		mergeSort(A, mid+1, high);
		merge(A, low, mid, high);
	}
}

#endif