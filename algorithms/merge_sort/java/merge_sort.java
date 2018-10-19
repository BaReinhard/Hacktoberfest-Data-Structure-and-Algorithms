/* Java program for Merge Sort */
class MergeSort
{
    static void merge_Sort(int  p, int r, int[] arr) {
		if(p<r) {
			int q =(p+r)/2;
			merge_Sort(p, q, arr);
			merge_Sort(q+1, r, arr);
			merge(p, q, r, arr);
		}
	}
	
	public static void merge(int p, int q, int r, int arr[]){
		int n1 = q-p+1;
		int n2 = r-q;
		int[] left = new int[n1+1];
		int[] right =  new int[n2+1];
		for(int i=0; i<n1; i++) {
			left[i]= arr[p+i];
			System.out.print(left[i]+" ");
		}
		System.out.println();
		for(int j=0; j<n2; j++) {
			right[j] = arr[q+j+1];
			System.out.print(right[j]+" ");
		}
		System.out.println();
		left[n1] = 999999999;
		right[n2] = 999999999;
		int i=0; 
		int j=0;
		for(int k=0; k<arr.length; k++) {
			if(left[i]<=right[j]) {
				arr[k]=left[i];
				i=i+1;
			}
			else {
				arr[k] = right[j];
				j=j+1;
			}
			System.out.print(arr[k]+" ");
		}
		System.out.println();
		for(int m=0; m<arr.length; m++) {
			System.out.print(arr[m]+" ");
		}
	}
	
	public static void main(String args[]) {
		int n = 8;
		int p = 0;
		int q = 3;
		int r = 7;
		int[] arr = { 1, 5, 3, 9, 2, 4, 6, 8 };
		
		merge_Sort(p, r, arr);
		
	}
}
