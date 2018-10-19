// Java program for implementation of Selection Sort
class SelectionSort
{
    static  int[] selectionSort(int[] arr) {
		for(int i=0; i<arr.length-1; i++){
			int min = i;
			for(int j=i+1; j<arr.length; j++) {
				if(arr[j]<arr[i]) {
					min = j;
					int temp = arr[min];
					arr[min]=arr[i];
					arr[i]=temp;
				}
			}
		}
		return arr;
		}
	
	public static void main(String[] args) {
		int[] arr = {23, 78, 45, 8, 32, 10,29};
		int[] result = selectionSort(arr);
		for(int i=0; i<result.length; i++) {
			System.out.print(result[i]+" ");
		}
	}
}
