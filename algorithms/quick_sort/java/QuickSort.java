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
    


    public static void main(String[] args) throws IOException {

        int n = 9;

        int[] arr = {-3, -10, -5, -7, 0, 6, 4, 8, 2};
        
        int p = 0;
        
        int r = arr.length-1;

        int[] result = quickSort(arr,p,r);

        for(int i=0; i<arr.length; i++) {
        	System.out.print(result[i]+" ");
        }
}
