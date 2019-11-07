import java.util.Arrays;

class QuickSort {
    public int partition(int[] arr, int start, int end) {
        int pivot = arr[end];
        int pIndex = start;
        for(int i = start; i < end; i++) {
            if(arr[i] <= pivot) {
                swap(arr[i], arr[pIndex]);
                pIndex++;
            }
        }
        swap(arr[pIndex], arr[end]);
        return pIndex;
    }

    public int[] sort(int[] arr, int start, int end) {
        if(start < end) {
            int partitionIndex = partition(arr, start, end);
            sort(arr, start, partitionIndex-1);
            sort(arr, partitionIndex+1, end);
        }
        return arr;
    }    

    public void swap(int low, int high) {
        int temp = low;
        low = high;
        high = temp;
    }

    public static void main(String[] args) {
        QuickSort obj = new QuickSort();
        int[] A = {7, 6, 5, 4, 3, 2, 1, 0};
        System.out.println(Arrays.toString(obj.sort(A, 0, 7)));
    }
}