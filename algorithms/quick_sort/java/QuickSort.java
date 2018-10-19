public class QuickSort{
	static int[] quickSort(int[] arr, int p, int r) {
    	if(p<r) {
    		int q = partition(arr,p,r);
    		quickSort(arr,p,q-1);
    		quickSort(arr,q+1,r);
    	}
        return arr;
    }
    
    static int partition(int[] arr, int p, int r) {
    	int pivot = arr[r];
    	int j = p-1;
    	for(int i=p; i<r; i++) {
    		if(arr[i]<=pivot) {
    			j=j+1;
    			int temp = arr[i];
    			arr[i] = arr[j];
    			arr[j] = temp;
    		}
    	}
    	arr[r]=arr[j+1];
    	arr[j+1]= pivot;
    	return j+1;
    }
	
	public static void main(String [] args){
		int [] arr = {9, 7, 5, 11, 12, 2, 14, 3, 10, 4, 6};
		System.out.print("Before: ");
		print(arr);
		quickSort(arr,0, arr.length-1);
		System.out.print("After: ");
		print(arr);
	}
}
