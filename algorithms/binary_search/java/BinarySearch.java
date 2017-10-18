// Java implementation of Binary Search
public class BinarySearch
{
    // Returns index of x if it is present in arr[l..r], else return -1
    int binarySearch(int array[], int left, int right, int x){
        if(array.length == 0) {
            return -1;
        }

        if (right >= left){
            int mid = left + (right - left) / 2;
            // If the search is present at the mid postion
            if (array[mid] == x){
                return mid;
            }
            // If element is smaller than mid, then it can only be in left subarray
            if (array[mid] > x){
                return binarySearch(array, left, mid - 1, x);
            }
            // Else the element can only be present in right subarray
            return binarySearch(array, mid + 1, right, x);
        }
        // We reach here when element is not present in array
        return -1;
    }

   int search(int [] array, int x) {
        return binarySearch(array, 0, array.length -1, x);

   }
    // Main method for testing
    public static void main(String[] args)
    {
        BinarySearch ob = new BinarySearch();
        int array[] = {1, 4, 5, 10, 11, 27, 36, 67, 90};
        int x = 10;
        int result = ob.search(array,  x);

        if (result == -1){
            System.out.println("Element not present");
        }
        else{
            System.out.println("Element found at index " + result);
        }
    }
}
