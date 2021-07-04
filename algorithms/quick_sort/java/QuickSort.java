public class QuickSort{
	/* The main function that implements QuickSort()
      arr[] --> Array to be sorted,
      low  --> Starting index,
      high  --> Ending index */
	static void quickSort(int[] arr,int start, int end){
		if (start < end){
			int pivot_pos = partition(arr,start,end);
			quickSort (arr,start, pivot_pos-1);
			quickSort (arr,pivot_pos+1, end);
		}
	}
	
	/* This function takes last element as pivot,
      places the pivot element at its correct
      position in sorted array, and places all
      smaller (smaller than pivot) to left of
      pivot and all greater elements to right
      of pivot */
	static int partition(int [] arr, int start, int end){
		int pivot = arr[end];
		int i = start, j = end - 1;
		while (i <= j) {
			if (arr[j] <= pivot && arr[i] > pivot){
				swap(arr,i,j);
			}
			if (arr[i] <= pivot) {
				i++;
			}
			if (arr [j] > pivot){
				j--;
			}
		}
		swap(arr,i,end);
		return i;
	}
	
	// swap arr[i+1] and arr[high] (or pivot)
	static void swap(int[] arr,int i, int j){
		int tmp = arr[i] ;
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	
	/* A utility function to print array of size n */
	static void print(int [] arr){
		for (int i = 0; i < arr.length; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
	}
	
	// Driver program
	public static void main(String [] args){
		int [] arr = {9, 7, 5, 11, 12, 2, 14, 3, 10, 4, 6};
		System.out.print("Before: ");
		print(arr);
		quickSort(arr,0, arr.length-1);
		System.out.print("After: ");
		print(arr);
	}
}
